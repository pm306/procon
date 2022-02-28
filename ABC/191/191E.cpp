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
  ll V,goal;
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
    goal = LINF;
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
        if(e.to==s){
              chmin(goal, d[v] + e.cost);
        }
        else if(d[e.to]>d[v]+e.cost){
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

    vector<ll> roop(n, LINF), ans(n);
    graph g(n);
    rep(i, m){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        if(a==b)chmin(roop[a], c);
        else g.add_edge(a,b,c);
    }

    rep(i, n){
            g.dijkstra(i);
            ll res = min(roop[i], g.goal);
            if(res==LINF)res = -1;
            ans[i] = res;
    }
    for(auto a: ans)cout << a << ln;
}

/////////////////////////////////////////
// 自己ループ＝最速、という盛大な勘違いを犯した。コストがあるのだから最速とは限らない。思い込みコワイ。
// また、多重辺の扱いに注意。多重辺はあらかじめmap等で除去しておくか、ダイクストラをいじる部分で全検討しないとミスりかねない。

// ダイクストラ自体の仕様を忘れてたのもまずい。加工に手間取った。

// 公式解法は逆向きグラフを利用して、街iから各町j(i!=j)に挟むようにして最短距離を求める
// 帰りがけを逆向きグラフとすれば、i-j-iの最短コストがわかる。各iについてjをすべて見れば良い。
