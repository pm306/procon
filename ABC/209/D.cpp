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

int color[101010];
void dfs(vector<vector<int>>& g, int v, int p, int c){
    color[v] = abs(c-1);
    fore(nv, g[v]){
        if(nv == p)continue;
        dfs(g, nv, v, color[v]);
    }
}

int main(){
    int N, Q; cin >> N >> Q;
    vector<vector<int>> g(N);
    rep(i, N-1){
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    dfs(g, 0, -1, 0);
    while(Q--){
        int x, y; cin >> x >> y; x--, y--;
        if(color[x] == color[y])cout << "Town" << ln;
        else cout << "Road" << ln;
    }
}

