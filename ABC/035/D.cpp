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
vector<ll> dijkstra(vector<vector<edge>>& g, int s){
    int n = g.size();
    vector<ll> d(n, INF); d[s] = 0;
    min_priority_queue<edge> que; que.push({0, s});

    while(que.size()){
        auto [c, v] = que.top(); que.pop();
        if(c > d[v])continue;

        for(auto& [nc, nv] : g[v]){
            if(chmin(d[nv], d[v] + nc)){
                que.push({d[nv], nv});
            }
        }
    }
    return d;
}

int main(){
    int N, M, T; cin >> N >> M >> T;
    vector<ll> A(N); rep(i, N)cin >> A[i];

    vector<vector<edge>> g1(N), g2(N);
    rep(i, M){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        g1[a].emplace_back(c,b);
        g2[b].emplace_back(c,a);
    }

    auto d1 = dijkstra(g1, 0);
    auto d2 = dijkstra(g2, 0);

    ll res = 0;
    rep(i, N){
        ll dist = d1[i] + d2[i];
        if(dist <= T){
            chmax(res, (T - dist) * A[i]);
        }
    }
    cout << res << ln;
}
