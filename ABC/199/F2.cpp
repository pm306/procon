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
using mat = vector<vector<mint>>;
//A*B
mat mul(mat& A, mat& B){
    mat C(A.size(), vector<mint>(B[0].size()));
    for(int i=0; i<A.size(); i++){
        for(int k=0; k<B.size(); k++){
            for(int j=0; j<B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}

//A^n
mat power(mat A, ll n){
    mat B(A.size(), vector<mint>(A.size()));
    for(int i=0; i<A.size(); i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if (n & 1) B = mul(B, A);
        A = mul(A, A); //Aを2乗
        n >>= 1;
    }
    return B;
}


int main(){
    int N, M, K; cin >> N >> M >> K;
    vector<int> A(N), deg(N);
    rep(i, N)cin >> A[i];

    //V[to][from]:=1回操作を行った時点で、頂点fromから頂点toへの寄与率(値の移動率)の期待値
    //例:V[1][0] = 0.25 の場合、1回の操作で平均して、頂点0の25%の値が頂点1に移動することを示す
    //期待値の線形性を利用して、K回後の期待値を1回後の期待値から

    /*
    入力例1のVの中身
    0.5 0.25 0.25
    0.25 0.75 0
    0.25 0 0.75
    */

    mat V(N, vector<mint>(N));
    rep(i, M){
        int x, y; cin >> x >> y; x--, y--;
        V[x][y] += mint(1) / (2*M);
        V[y][x] += mint(1) / (2*M);
        deg[x]++;
        deg[y]++;
    }

    //頂点の値がそのまま残るパターン
    //別の辺が選ばれるパターン + その頂点を含む辺が選ばれるパターン / 2
    rep(i, N)V[i][i] += mint(2*M-deg[i]) / (2*M);

    V = power(V, K);

    vector<mint> ans;
    rep(to, N){
        mint res = 0;
        rep(from, N){
            res += V[to][from] * A[from];
        }
        ans.push_back(res);
    }
    fore(a,ans)cout << a.val() << ln;
}

