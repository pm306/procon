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

/*
実装問題
*/


int main(){
    int N, M; cin >> N >> M;
    vector<vector<ll>> A(N);
    rep(i, N){
        int k; cin >> k;
        rep(j, k){
            int a; cin >> a;
            A[i].push_back(a);
        }
    }
    int P, Q; cin >> P >> Q;
    vector<ll> B(P); rep(i, P)cin >> B[i];

    int res = 0;
    rep(i, N){
        int cnt = 0;
        rep(j, P){
            if(count(all(A[i]), B[j]))cnt++;
        }
        if(cnt >= Q)res++;
    }
    cout << res << ln;
}
