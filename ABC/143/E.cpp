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
    int n, m, L; cin >> n >> m >> L;

    vector dp(n, vector<ll>(n, INF));
    rep(i, m){
        int a, b; ll w; cin >> a >> b >> w; a--, b--;
        dp[a][b] = dp[b][a] = w;
    }
    rep(i, n)dp[i][i] = 0;

    rep(k, n)rep(i, n)rep(j, n)chmin(dp[i][j], dp[i][k] + dp[k][j]);

    vector dp2(n, vector<ll>(n, INF));
    rep(i, n)rep(j, n){
        if(i == j) dp2[i][j] = 0;
        else if(dp[i][j] <= L) dp2[i][j] = 1;
    }

    rep(k, n)rep(i, n)rep(j, n)chmin(dp2[i][j], dp2[i][k] + dp2[k][j]);

    int q; cin >> q;
    vector<int> ans;
    while(q--){
        int s, t; cin >> s >> t; s--, t--;
        ans.push_back(dp2[s][t] == INF ? -1 : dp2[s][t] - 1);
    }

    fore(a, ans) cout << a << ln;
}
