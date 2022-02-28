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

//いもす法(累積和)によるDP高速化
//遷移パターンは入力例1がわかりやすい

using mint = modint1000000007;

mint dp[110][101010];
int main(){
    int N, K; cin >> N >> K;
    vector<int> A(N); rep(i, N) cin >> A[i];

    dp[0][0] = 1;
    rep(i, N){
        rep(j, K+1){
            dp[i+1][j] += dp[i][j];
            dp[i+1][min(K+1, j+A[i]+1)] -= dp[i][j];
        }
        rept(j,1, K+1){
            dp[i+1][j] += dp[i+1][j-1];
        }
    }

    cout << dp[N][K].val() << ln;
}


