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

using mint = modint998244353;

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

ll H, W;

//1回遷移した場合の数Vを再帰関数で作成
//0~1<<H-1までの全fromを回して表を作る
//1回の呼び出しで計算量3^6=729回。1000*1000 = 1e6程度、と見積もる
void dfs(auto& V, int from, int to, int pos){
    if(pos == H){
        V[to][from]++;
        return;
    }
    //そのマスが使用済み
    if(from>>pos&1)dfs(V, from, to, pos+1);
    //未使用
    else{
        //下に敷く
        if(pos != H-1 and !(from>>(pos+1)&1))dfs(V, from, to, pos+2);
        //右に敷く。論理演算で行き先の右マスを埋める
        dfs(V, from, to | 1<<pos, pos+1);
        //ちいさい
        dfs(V, from, to, pos+1);
    }
}

int main(){
    cin >> H >> W;
    mat V(1<<H, vector<mint>(1<<H));

    rep(bit, 1<<H)dfs(V, bit, 0, 0); //すべてのスタートパターンを作成

    auto A = power(V, W);
    cout << A[0][0].val() << ln;
}

