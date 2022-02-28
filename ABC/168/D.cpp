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
////////////////////////////////////////////////////////////////////////////////////////////////////////

// 1に隣接してる頂点は必ず1を指す
// ↑に隣接してる頂点は必ずその頂点を指す

// 頂点1からの距離がvの頂点は、距離v-1の頂点を指すことで、必ず到達できる

vector<ll> bfs(vector<vector<int>>& g, int s){
    int n = g.size();
    vector<ll> dist(n, INF); dist[s] = 0;
    queue<int> que; que.push(s);

    while(!que.empty()){
        int v = que.front(); que.pop();

        for(auto& nv: g[v]){
            if(dist[nv] == INF){
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }
    return dist;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto dist = bfs(g, 0);
    vector<int> D(n);//頂点1との最短距離がD[i]である頂点番号を1つ挙げる
    rep(i, n) D[dist[i]] = i;

    cout << "Yes" << ln;
    rept(i, 1, n)cout << D[dist[i]-1] + 1 << ln;
}
