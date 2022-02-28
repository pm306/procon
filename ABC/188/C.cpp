#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int N; cin >> N; N = 1 << N; //累乗はビットシフトが安全
    vector<pll> A(N);
    rep(i, N){
        int a; cin >> a;
        A[i] = {i, a};
    }

    while(true){
        if(A.size()==2){
            if(A[0].second > A[1].second) cout << A[1].first + 1 << ln;
            else cout << A[0].first + 1 << ln;
            return 0;
        }

        vector<pll> v;
        for(int i=0; i<A.size(); i+=2){
            if(A[i].second > A[i+1].second)v.push_back(A[i]);
            else v.push_back(A[i+1]);
        }
        A = v;
    }
}
