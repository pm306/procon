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

using pll = pair<ll, ll>;

int main(){
    int N; cin >> N;
    vector<vector<pll>> g(N);
    rep(i, N-1){
        int a, b; ll c; cin >> a >> b >> c; a--, b--;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }

    int Q, K; cin >> Q >> K; K--;

    //前処理 頂点Kを根とした木の距離を記録
    vector<ll> d(N);
    auto dfs = [&](auto&& self, int v, int p, ll cost) -> void{
        d[v] = cost;
        for(auto& [nv, c] : g[v]){
            if(nv == p)continue;
            self(self, nv, v, cost + c);
        }
    };
    dfs(dfs, K, -1, 0);

    vector<ll> ans;
    while(Q--){
        int x, y; cin >> x >> y; x--, y--;
        ans.push_back(d[x] + d[y]);
    }
    fore(a, ans)cout << a << ln;
}

