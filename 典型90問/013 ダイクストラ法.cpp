#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
1 -> k -> N を 1 -> k <- N に読み替えて2回ダイクストラ法を実行するだけ
*/

struct edge{ll to, cost;};
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

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
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
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
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
    int N, M; cin >> N >> M;
    graph g(N);
    rep(i, M){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        g.add_edge(a,b,c);
        g.add_edge(b,a,c);
    }
    vector<ll> dist1(N), dist2(N);
    g.dijkstra(0);
    rep(i, N)dist1[i] = g.d[i];
    g.dijkstra(N-1);
    rep(i, N)dist2[i] =g.d[i];
    rep(i, N){
        cout << dist1[i] + dist2[i] << ln;
    }
}
