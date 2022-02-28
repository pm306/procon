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

mint dp[1<<21];
int main(){
    int N; cin >> N;
    int A[22][22]; rep(i, N)rep(j, N)cin >> A[i][j];

    dp[0] = 1;
    rept(S, 1, 1<<N){
        int i = __builtin_popcount(S);
        rep(j, N)if(S>>j&1 and A[i-1][j])dp[S] += dp[S^(1<<j)];// 集合に存在 and マッチング可能
    }
    cout << dp[(1<<N)-1].val() << ln;
}


