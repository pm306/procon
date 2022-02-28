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
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int, int>> edge(n-1);
    rep(i, n-1){
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        edge[i] = {a, b};
    }

    vector<int> depth(n);
    auto getDepth = [&](auto getDepth, int v, int p, int d) -> void{
        depth[v] = d;
        for(auto &e:g[v]){
            if(e == p)continue;
            getDepth(getDepth, e, v, d+1);
        }
    };
    getDepth(getDepth, 0, -1, 0);

    vector<ll> eval(n);
    int q; cin >> q;
    while(q--){
        int t, e; ll x; cin >> t >> e >> x; e--;
        auto [a, b] = edge[e];
        if(t==2)swap(a, b);

        if(depth[a] > depth[b]){
            eval[a] += x;
        }
        else{
            eval[0] += x;
            eval[b] -= x;
        }
    }

    vector<ll> ans(n);
    auto dfs = [&](auto&& self, int v, int p, ll val) -> void{
        val += eval[v];
        ans[v] = val;
        fore(nv, g[v]){
            if(nv == p)continue;
            self(self, nv, v, val);
        }
    };
    dfs(dfs, 0, -1, 0);

    fore(a, ans)cout << a << ln;
}


