#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
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
行列累乗
１：頂点ごとの寄与率をVに格納して繰り返し二乗法でK回先の遷移行列を作る
２：出来上がった行列ansと各Aを演算して期待値を求める

寄与率
頂点x,yに辺が貼られていた場合、V[x][y], V[y][x] 共に += 1/2M(寄与率1/2, 確率1/M)
貼られてない場合はまとめて計算する。V[i][i] += (2M-deg[i])/2M

*/

using mint = modint1000000007;
using mat = vector<vector<mint>>;
//A*B
mat mul(mat& A, mat&B){
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
mat pow(mat A, ll n){
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

    //1回遷移後の行列
    mat V(N, vector<mint>(N));
    rep(i, M){
        int x, y; cin >> x >> y; x--, y--;
        //辺が貼られている場合
        //頂点それぞれが1/2Mだけ寄与する
        V[x][y] += mint(1) / (2*M);
        V[y][x] += mint(1) / (2*M);
        //次数を記録
        deg[x]++;
        deg[y]++;
    }

    //関わりのない辺が選ばれた場合
    //(2M-deg[i]) / 2M
    rep(i, N)V[i][i] += mint(2*M-deg[i]) / (2*M);

    //行列演算
    auto ans = pow(V, K);
    //操作をK回行った後、vに寄与する期待値を求める
    //from:all, to:v
    rep(i, N){
        mint res = 0;
        rep(j, N){
            res += ans[i][j] * A[j]; //添え字に注意
        }
        cout << res.val() << ln;
    }
}
