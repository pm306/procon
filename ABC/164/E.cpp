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
using edge = pair<int, int>; //to, edge_index
using graph = vector<vector<edge>>;

int main(){
    int N, M, S; cin >> N >> M >> S;
    chmin(S, 3000);//移動に必要な銀貨は高々50*50=2500枚くらいなので3000枚まで減らす
    graph g(N);
    int A[101], B[101], C[50], D[50];
    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        cin >> A[i] >> B[i];
        g[u].emplace_back(v, i);//辺番号も記録
        g[v].emplace_back(u, i);
    }
    rep(i, N)cin >> C[i] >> D[i];

    vector dist(N, vector<ll>(3000, INF)); //dist[i][s]:=頂点iにいて、銀貨をs枚持っている場合の最短距離

    vector<ll> ans(N, INF);

    min_priority_queue<tuple<ll, int, int>> que; //cost, vertex, S

    dist[0][S] = 0;
    que.push({0, 0, S});

    while(que.size()){
        auto [cost, v, s] = que.top(); que.pop();
        if(dist[v][s] < cost)continue;

        chmin(ans[v], cost);

        //他の街へ移動する
        for(auto [to, i]:g[v]){
            if(s < A[i])continue; //銀貨が足りなくて移動できない

            ll cost2 = cost + B[i];
            if(chmin(dist[to][s - A[i]], cost2)){
                que.push({dist[to][s-A[i]], to, s-A[i]});
            }
        }

        //街を移動せず、両替する
        ll cost2 = cost + D[v]; //両替
        int s2 = min(3000, s + C[v]);
        if(chmin(dist[v][s2], cost2)){
            que.push({dist[v][s2], v, s2});
        }
    }
    rept(i, 1, N)cout << ans[i] << ln;
}


