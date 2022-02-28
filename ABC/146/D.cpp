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



int main(){
    int n; cin >> n;

    vector<vector<pair<int, int>>> g(n); //to, edge_index
    rep(i, n-1){
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }

    vector<int> ans(n-1);
    auto dfs = [&](auto dfs, int v, int p, int p_col) -> void{
        int color = 1;
        for(auto [to, idx]:g[v]){
            if(to == p)continue;
            if(color == p_col)color++;
            ans[idx] = color++;
            dfs(dfs, to, v, ans[idx]);
        }
    };

    dfs(dfs, 0, -1, -1);

    cout << *max_element(all(ans)) << ln;
    fore(a, ans)cout << a << ln;
}
