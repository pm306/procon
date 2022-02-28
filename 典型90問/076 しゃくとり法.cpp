#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    int N; cin >> N;
    vector<ll> A(N*2);
    rep(i, N)cin >> A[i], A[N+i] = A[i];

    ll num = accumulate(A.begin(), A.begin()+N, 0LL);
    if(num%10){
        cout << "No" << ln;
        return 0;
    }
    num /= 10;

    ll sum = 0, r = 0;
    for(int l=0; l<N*2; l++){
        while(r<N*2){
            if(sum >= num)break;
            sum += A[r++];
        }
        if(sum == num){
            cout << "Yes" << ln;
            return 0;
        }
        if(r==l)r++;
        sum -= A[l];
    }
    cout << "No" << ln;
}

