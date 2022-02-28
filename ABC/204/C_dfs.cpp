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

/*
公式解。
訪れた頂点数 = seen[v] = true となるvの数 なので配列の合計値を足し合わせれば良い。

dfsは書くこと少なくて楽だ。
*/

vector<vector<int>> g;
vector<int> seen(2000);
void dfs(int v){
    if(seen[v])return;
    seen[v] = true;
    for(auto& vv:g[v])dfs(vv);
}

int main(){
    int N, M; cin >> N >> M;
    g.resize(N);
    rep(i, M){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
    }

    int res = 0;
    rep(i, N){
        seen.assign(N, false);
        dfs(i);
        res += accumulate(all(seen), 0);
    }
    cout << res << ln;
}
