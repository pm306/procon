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

const int MAX_S = 3000;
int n, m, s;
ll C[55], D[55];

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using edge = tuple<int, ll, ll>; //to, ginka, time
using graph = vector<vector<edge>>;

void dijkstra(graph& g, int start, int ginka){
    int n = g.size();
    //vector<ll> dist(n, INF); dist[s] = 0;
    vector dist(n, vector<ll>(MAX_S, INF)); dist[start][ginka] = 0;
    min_priority_queue<tuple<ll, int, int>> que; que.push({0, start, ginka}); //cost, to, s

    while(que.size()){
        auto [c, v, s] = que.top(); que.pop();
        if(c > dist[v][s])continue;

        //可能なら銀貨を支払って移動する
        for(auto& [nv, ns, nt] : g[v]){
            if(s >= ns and chmin(dist[nv][s-ns], dist[v][s] + nt)){
                que.push({dist[nv][s-ns], nv, s-ns});
            }
        }
        //両替する
        int nx_s = min(3000ll, s+C[v]);
        if(chmin(dist[v][nx_s], c + D[v]))
            que.push({c + D[v], v, min(3000, nx_s)});
    }

    rept(i, 1, n){
        ll res = INF;
        rep(j, 3000)chmin(res, dist[i][j]);
        cout << res << ln;
    }
}

int main(){
    cin >> n >> m >> s;
    graph g(n);
    rep(i, m){
        ll u, v, a, b; cin >> u >> v >> a >> b; u--, v--;
        g[u].emplace_back(v, a, b);
        g[v].emplace_back(u, a, b);
    }
    rep(i, n)cin >> C[i] >> D[i];

    dijkstra(g, 0, min(3000, s));
}

