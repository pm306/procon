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

/*
・union-findで回答の可否を判定
・情報を先に整理して基準となる数列を作る
・x,yの差の偶奇で答えが反転する

考えることが多い……
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

ll T[101010], X[101010], Y[101010], V[101010];
int main(){
    int N, Q; cin >> N >> Q;
    rep(i, Q)cin >> T[i] >> X[i] >> Y[i] >> V[i], X[i]--, Y[i]--;

    vector<ll> wa(101010, -1);//wa[i] = A[i] + A[i+1] 不明なら-1
    rep(i, Q){
        if(T[i]==1)continue;
        wa[X[i]] = V[i];
    }
    //A[0] = 0 とした時の数字列を先に作る。不明な場合は使わないので0にしておく
    vector<ll> A(N); A[0] = 0;
    rep(i, N-1){
        if(wa[i] != -1){
            A[i+1] = wa[i] - A[i];
        }
    }

    //answer query
    UnionFind uf(N);
    rep(i, Q){
        if(T[i]==0){
            uf.merge(X[i], Y[i]);
        }
        else{
            if(!uf.issame(X[i], Y[i])){
                cout << "Ambiguous" << ln;
            }
            else{
                ll sa = A[X[i]] - V[i]; //0-basedの値 - ?-basedの値
                if((Y[i]-X[i])%2!=0)sa = -sa;
                cout << A[Y[i]] - sa << ln;
            }
        }

    }
}
