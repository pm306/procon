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
////////////////////////////////////////////////////////////////////////////////////////////////////////

using mint = modint998244353;

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);
    rep(i, m){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    //dp[i+i][j] = sum[dp[i]] - dp[j] - Σdp[隣接頂点]
    vector<mint> dp(n);
    dp[0] = 1;
    rep(i, k){
        vector<mint> next(n);
        mint sum = 0; fore(a, dp)sum += a;
        rep(j, n){
            next[j] = sum - dp[j];
            fore(to, g[j])next[j] -= dp[to];
        }
        dp = next;
    }
    cout << dp[0].val() << ln;
}

