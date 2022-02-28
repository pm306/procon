#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
拡張ダイクストラ法
辺に「時間」の概念が加わる
*/

struct edge{ll to, time, cost;};
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;
  vector<ll> prev;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i] = LINF;
    }
  }

  void add_edge(ll s, ll t, ll cost, ll time){
    edge e;
    e.to = t, e.time = time, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    rep(i,V){
      d[i] = LINF;
    }
    d[s] = 0;
    priority_queue<pll,vector<pll>, greater<pll> > que;
    que.push(pll(0,s)); //[その頂点への最短コスト候補、頂点番号]
    prev.assign(V, -1);
    while(!que.empty()){
      pll p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
          ll ncost = d[v];
          if(ncost % e.time){
              ncost += e.time - (ncost % e.time);
          }
          ncost += e.cost;
        if(d[e.to]>ncost){
          d[e.to] = ncost;
          prev[e.to] = v;
          que.push(pll(d[e.to],e.to));
        }
      }
    }
  }

  vector<int> get_path(int t){ //頂点tへの最短路
    vector<int> path;
    for(; t != -1;t=prev[t]){
        path.push_back(t);
    }

    reverse(path.begin(), path.end());
    return path;
  }
};


int main(){
    int N, M, X, Y; cin >> N >> M >> X >> Y; X--, Y--;
    graph g(N);
    rep(i, M){
        int a, b; ll t, k; cin >> a >> b >> t >> k; a--, b--;
        g.add_edge(a,b,t,k);
        g.add_edge(b,a,t,k);
    }

    g.dijkstra(X);
    cout << (g.d[Y] == LINF ? -1 : g.d[Y]) << ln;
}
