#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
直径＝単純パスの長さの最大値　を高速に求められますか？　という問題
木にパスを１本足した時の閉路の最大長を求める
→単純パスの最大長(木の直径) + 1 が答え

直径の求め方 O(N)
1:適当な始点から距離を探索し、直径の瑞点A(最も遠い点)を求める
2:瑞点Aから距離を探索し、もう片方の瑞点B(最も遠い点)を求める
瑞点Aと瑞点Bの距離が木の直径となる
*/

using graph = vector<vector<int>>;

int main(){
    int N; cin >> N;
    graph G(N);
    rep(i, N-1){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N);
    auto dfs = [&](auto&& self, int v, int p, int d) -> void{
        dist[v] = d;
        for(auto e: G[v]){
            if(e == p)continue;
            self(self, e, v, d+1);
        }
    };
    //step1: 適当な頂点から距離を探索する
    dfs(dfs, 0, -1, 0);
    //最も遠い頂点番号uを取得
    int u = max_element(all(dist)) - dist.begin();
    //stap2: uを始点として距離を探索する
    dfs(dfs, u, -1, 0);
    //step3: uからの単純パスの最大値が直径
    cout << *max_element(all(dist)) + 1 << ln;
}
