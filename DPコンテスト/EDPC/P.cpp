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
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using mint = modint1000000007;

int main(){
    int N; cin >> N;
    vector<vector<int>> g(N);
    rep(i, N-1){
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    vector memo(N, vector<mint>(2));
    auto dp = [&](auto dp, int v, int p, int c) -> mint{
        if(v and g[v].size() == 1)return (mint)1;

        if(memo[v][c].val() != 0)return memo[v][c].val();

        mint ret = 1;
        fore(e, g[v]){
            if(e == p)continue;
            mint val = dp(dp, e, v, 1); //white paint
            if(c)val += dp(dp, e, v, 0); //black paint
            ret *= val;
        }
        return memo[v][c] = ret;
    };

    cout << (dp(dp, 0, -1, 0) + dp(dp, 0, -1, 1)).val() << ln;
}


