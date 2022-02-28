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

/*
全域木
コンピュータネットワークで重要な位置を占める
頂点＝ルータ、スイッチングハブ
辺：ケーブル
とみなすと、ネットワークをグラフと見做せる。

STPという、データリンク層(第2層)のプロトコルがある。LAN内でループ構成を回避するための通信プロトコル。
STP = スパニングツリー(全域木)の名の通り、を用いている。

サンプル入力
8 12
1 2 4
1 3 2
1 4 9
2 3 3
3 5 7
2 6 8
4 5 5
4 8 10
5 6 6
5 7 3
6 7 5
7 8 6
ans = 31
*/

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
}

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
}

    int size(int x) {
        return -par[root(x)];
    }
};

using edge = tuple<ll, int, int>;//weight, u, v

int main(){
    int N, M; cin >> N >> M;
    vector<edge> E(M);
    rep(i, M){
        int u, v; ll w; cin >> u >> v >> w; u--, v--;
        E[i] = {w, u, v};
    }

    sort(all(E)); //辺集合を重みの小さい順にソート

    //クラスカル法
    ll res = 0;
    UnionFind uf(N);
    rep(i, M){
        auto [w, u, v] = E[i];
        if(uf.issame(u, v))continue; //2頂点が連結かどうかunion-findで判定
        uf.merge(u, v);
        res += w;
    }
    cout << res << ln;
}

