#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> bfs(vector<vector<int>>& g, int from){
    int n = g.size(); //頂点数
    vector<ll> dist(n);
    for(int i=0; i<n; i++){
        dist[i] = i == from ? 0 : LINF;
    }
    queue<int> que;
    que.push(from);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto e: g[v]){
            if(dist[e] == LINF){
                dist[e] = dist[v] + 1;
                que.push(e);
            }
        }
    }
    return dist;
}

ll shortest_Hamiltonaian_Path(vector<vector<ll>>& adj, bool is_cycle = false, int s = -1){
    int k = adj.size();
    ll inf = 1LL<<60;
    //dp[mask][i]:=通過済みの地点の集合がmaskで、現在地が頂点iである場合の最小コスト
    vector<vector<ll>> dp(1 << k, vector<ll>(k, inf));

    //init
    //複数始点
    if(s==-1)for(int i=0; i<k; i++)dp[0][i] = 0;
    //単一始点
    else dp[0][s] = 0;

    for(int mask=1; mask<(1<<k)-1; mask++){
        for(int i=0; i<k; i++){
            if(!(mask >> i & 1)){
                for(int j=0; j<k; j++){
                    if(mask >> j & 1){
                        chmin(dp[mask][i], adj[j][i] + dp[mask ^ 1 << j][j]);
                    }
                }
            }
        }
    }
    ll res = inf;
    rep(i, k)chmin(res, dp[((1<<k)-1) ^ 1 << i][i] + (is_cycle ? adj[i][s] : 0));
    return res;
}

int main(){
    int N, M, K; cin >> N >> M;
    vector<vector<int>> g(N);
    rep(i, M){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> K;
    vector<int> C(K);
    rep(i, K)cin >> C[i], C[i]--;

    //各Cどうしの最短距離
    vector<vector<ll>> adj(K, vector<ll>(K)); //adjust:調整する？
    rep(i, K){
        auto dist = bfs(g, C[i]);
        rep(j, K){
            adj[i][j] = dist[C[j]];
        }
    }
    ll res = shortest_Hamiltonaian_Path(adj);
    cout << (res == LINF ? -1 : res + 1) << ln;
}
