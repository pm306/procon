#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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

int main(){
    int N; cin >> N;
    vector<int> A(N); rep(i, N)cin >> A[i];

    UnionFind uf(200010);
    for(int i=0; i*2<N; i++){
        uf.merge(A[i], A[N-1-i]);
    }

    vector<int> cnts(200010);
    //集合の親(ラベル)をカウントする=集合ごとの要素数をカウントできる
    for(int i=0; i<200010; i++){
        cnts[uf.root(i)]++;
    }

    int res = 0;
    for(int x:cnts)res += max(x-1, 0); //要素0のことがある
    cout << res << ln;
}

