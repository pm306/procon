#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> C(n, vector<ll>(n, INF));
    rep(i, m){
        int s, t, d; cin >> s >> t >> d;
        C[s][t] = d;
    }

    //dp[S][v]:=通過済みの頂点集合がS, 最後に通過した頂点がv
    //init dp[1][0] = 0
    //ans  min(dp[1<<n-1][v] + C[v][0])
    //遷移
    //dp[S][u] + C[u][v] -> dp[S | v][v]

    vector dp(1<<n, vector<ll>(n, INF));
    dp[1][0] = 0;
    for(int S=1; S<1<<n; S++){
        for(int u=0; u<n; u++){
            for(int v=0; v<n; v++){
                if(!(S>>u&1) or S>>v&1)continue;
                chmin(dp[S | 1<<v][v], dp[S][u] + C[u][v]);
            }
        }
    }

    ll res = INF;
    rep(i, n)chmin(res, dp[(1<<n)-1][i] + C[i][0]);
    if(res == INF)res = -1;
    cout << res << ln;
}
