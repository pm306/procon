#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using mint = modint1000000007;

mint dp[101010][3];
int main(){
    int N; cin >> N;
    char C[101010]; rep(i, N)cin >> C[i];
    vector<vector<int>> G(N);
    rep(i, N-1){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    auto dfs = [&](auto&& self, int pos, int p) -> void{
        mint val1 = 1, val2 = 1;
        fore(i, G[pos]){
            if(i == p)continue;
            self(self, i, pos);
            val1 *= dp[i][C[pos] - 'a'] + dp[i][2];
            val2 *= (dp[i][0] + dp[i][1] + dp[i][2] * 2);
        }
        dp[pos][C[pos] - 'a'] = val1;
        dp[pos][2] = val2 - val1;
    };

    dfs(dfs, 0, -1);
    cout << dp[0][2].val() << ln;
}

