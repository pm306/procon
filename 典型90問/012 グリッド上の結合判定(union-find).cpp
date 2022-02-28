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
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
グリッド上の座標を整数で管理して、Union-findで結合、判定を行う問題。
整数変換とr,cを勘違いして死ぬほど間違えた
発想はあってた
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

int isRed[2000*2000];

int main(){
    int H, W; cin >> H >> W;

    UnionFind uf(H*W);
    auto pton = [&](int y, int x) -> int{//座標を整数値に変換
        return y * W + x;
    };

    vector<string> ans;
    int Q; cin >> Q;
    while(Q--){
        int t; cin >> t;
        if(t == 1){
            int y, x; cin >> y >> x; y--, x--;
            int point = pton(y, x);
            //赤く塗る
            isRed[point] = true;
            //上
            if(y and isRed[point - W])uf.merge(point, point - W);
            //下
            if(y < H-1 and isRed[point + W])uf.merge(point, point + W);
            //左
            if(x and isRed[point - 1])uf.merge(point, point - 1);
            //右
            if(x < W-1 and isRed[point + 1])uf.merge(point, point + 1);
        }else{
            int ya, xa, yb, xb; cin >> ya >> xa >> yb >> xb; xa--, ya--, xb--, yb--;
            int from = pton(ya, xa), to = pton(yb, xb);
            if(isRed[from] and isRed[to] and uf.issame(from, to))ans.push_back("Yes");
            else ans.push_back("No");
        }
    }
    for(auto a:ans){
        cout << a << ln;
    }
}
