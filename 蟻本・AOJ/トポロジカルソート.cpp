#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
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

//トポロジカルソート
//なにそれ：DAGの頂点をソートするアルゴリズム
//何が嬉しいの？:わからん

int main(){
    int N, M; cin >> N >> M;
    vector<vector<int>> g(N);
    vector<int> indegree(N);
    rep(i, M){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        indegree[b]++;
    }

    /*
    お気持ち
    　入次数0の頂点を１つ選択する
    　その頂点より前に来る頂点はないので、配列の末尾に追加する(最後に反転する)
      グラフから頂点ｖを削除し、その頂点から出てる辺も全部消す
    のループ
      素朴な実装だと入次数のチェックでO(N)かかる
      →頂点削除時に入次数が変化する頂点は、削除した頂点の隣接頂点のみ
      →辺を削除した時に入次数が0になるかチェックすれば高速になる！
    */

    vector<int> V;
    queue<int> que;
    rep(i, N)if(indegree[i]==0)que.push(i);

    while(que.size()){
        int v = que.front(); que.pop();
        fore(nv, g[v]){
            indegree[nv]--;
            if(indegree[nv] == 0)que.push(nv);
        }
        V.push_back(v);
    }
    fore(v,V)cout << v << ln;
}

