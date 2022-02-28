#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
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
    int N; ll K; cin >> N >> K;
    int A[50][50]; rep(i, N)rep(j, N)cin >> A[i][j];

    mat V(N, vector<mint>(N));
    rep(i, N)rep(j, N)if(A[i][j])V[j][i]++;

    auto ans = power(V, K);
    mint res = 0;
    rep(i, N)rep(j, N)res += ans[j][i];
    cout << res.val() << ln;
}
