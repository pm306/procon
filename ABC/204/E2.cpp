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


template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using edge = pair<ll, int>; // cost, to
using graph = vector<vector<tuple<int, ll, ll>>>; //b, c, d;
ll dijkstra(graph& g, int s, int t){
    int n = g.size();
    vector<ll> dist(n, INF); dist[s] = 0;
    min_priority_queue<edge> que; que.push({0, s});

    while(que.size()){
        auto [c, v] = que.top(); que.pop();
        if(c > dist[v])continue;

        for(auto& [nv, c, d] : g[v]){
            //即座に出発する場合。t = dist[v]。
            ll nx_cost = dist[v] + c + d / (dist[v] + 1);
            //f(t):=時刻tに頂点を出発したときに次の頂点に到着するコスト
            //f(t)の最小値を求める。最小値はdが√d付近にあるのがわかるので探索する
            for(int lt=max(0, (int)sqrt(d)-2); lt<=(int)sqrt(d)+2; lt++){ //lt = leave time
                if(lt < dist[v])continue;
                chmin(nx_cost, lt + c + d / (lt + 1));
            }

            if(chmin(dist[nv], nx_cost)){
                que.push({dist[nv], nv});
            }
        }
    }
    return dist[n-1] == INF ? -1 : dist[n-1];
}

int main(){
    int N, M; cin >> N >> M;
    graph g(N);
    rep(i, M){
        ll a, b, c, d; cin >> a >> b >> c >> d; a--, b--;
        g[a].emplace_back(b, c, d);
        g[b].emplace_back(a, c, d);
    }

    cout << dijkstra(g, 0, N-1) << ln;
}
