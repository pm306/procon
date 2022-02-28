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
    int n, x, y; cin >> n >> x >> y; x--, y--;
    vector<vector<int>> g(n);
    rep(i, n-1){
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    g[x].push_back(y);
    g[y].push_back(x);

    vector<int> cnt(n);
    rep(i, n){
        auto dist = bfs(g, i);
        fore(d, dist)cnt[d]++;
    }
    rept(i, 1, n)cout << cnt[i] / 2 << ln;
}
