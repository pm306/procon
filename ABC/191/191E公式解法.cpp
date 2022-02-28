#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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
    int n, m; cin >> n >> m;

    vector<ll> ans(n,LINF);
    graph g1(n), g2(n);
    rep(i, m){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        if(a==b)chmin(ans[a], c);
        else{
            g1.add_edge(a,b,c);
            g2.add_edge(b,a,c);
        }
    }

    rep(i, n){
        g1.dijkstra(i);
        g2.dijkstra(i);
        rep(j, n){
            if(i==j)continue;
            chmin(ans[i], g1.d[j] + g2.d[j]);
        }
        if(ans[i]==LINF) ans[i] = -1;
    }
    for(auto a: ans)cout << a << ln;
}

/////////////////////////////////////
// 自己ループの最小コストの求め方が違う
// 頂点iから各頂点jへの最小コストを求める
// 各頂点jから頂点iへの最小コストを求める  
// という風に処理を分割する

// 前者は普通にダイクストラ
// 後者は愚直にやるとO(n^3)でTLEなので、辺を逆張りしたグラフでゴール側からダイクストラする。なるほど賢い。
