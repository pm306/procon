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

using mint = modint1000000007;

vector<mint> bfs(vector<vector<int>>& g, int s){
    int n = g.size();
    vector<ll> dist(n, INF); dist[s] = 0;
    queue<int> que; que.push(s);
    vector<mint> cnt(n); cnt[s] = 1;

    while(!que.empty()){
        int v = que.front(); que.pop();

        for(auto& nv: g[v]){
            if(dist[nv] == dist[v] + 1)cnt[nv] += cnt[v];
            if(dist[nv] == INF){
                dist[nv] = dist[v] + 1;
                que.push(nv);
                cnt[nv] += cnt[v];
            }
        }
    }
    return cnt;
}

int main(){
    ll N, M; cin >> N >> M;
    vector<vector<int>> g(N);
    rep(i, M){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << bfs(g, 0).back().val() << ln;
}
