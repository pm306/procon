#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1<<30;
constexpr long long LINF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
ライブラリを使わない書き方
シンプルですね
*/


int main(){
    int N; cin >> N;
    vector<int> T(N); rep(i, N)cin >> T[i];
    vector<vector<ll>> adj(N, vector<ll>(N));
    rep(i, N)rep(j, N)cin >> adj[i][j];

    vector<ll> dp(1<<N, LINF);
    dp[0] = 0;
    rep(mask, 1<<N) rep(i, N) if(!(mask>>i&1)){
        ll t = T[i];
        rep(j, N)if(mask>>j&1)t -= adj[j][i];
        chmin(dp[mask + (1<<i)], dp[mask] + t);
    }
    cout << dp[(1<<N)-1] << ln;
}
