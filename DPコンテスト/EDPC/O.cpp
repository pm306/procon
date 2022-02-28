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
bitDPぽい
が、男女両方を集合として持つと間に合わないので片方を順番に見ていく
dp[i][mask]:=男を前i人マッチングさせて、マッチングした女の集合がmaskである場合の数
計算量O(2^N*N^2) N=21なので実は間に合わない

以下の事実に着目する
・マッチングした男とビットが立っている女が一致するケースのみ見れば良い
1人目の男をマッチングさせるとき、女の集合maskは立っているビットが0個
2人目の男のとき、maskに立っているビットは1個
....
これらの状態のみが有効
すると
？
*/

using mint = modint1000000007;

mint dp[22][1<<21];
int main(){
    int N; cin >> N;
    int A[22][22]; rep(i, N)rep(j, N)cin >> A[i][j];

    dp[0][0] = 1;

    rep(i, N)rep(mask, 1<<N){
        if(i == __builtin_popcount(mask)){
            rep(j, N)if(!(mask>>j&1) and A[i][j]){ //まだマッチングしてない and マッチング可能
                dp[i+1][mask | (1<<j)] += dp[i][mask];
            }
        }
    }
    cout << dp[N][(1<<N)-1].val() << ln;
}


