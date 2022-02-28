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
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


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
    int N, M; cin >> N >> M;
    vector<vector<int>> g(N);
    rep(i, M){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
    }

    int res = 0;
    rep(i, N){
        auto d = bfs(g, i);
        rep(j, N)if(d[j]!=INF)res++;
    }
    cout << res << ln;
}
