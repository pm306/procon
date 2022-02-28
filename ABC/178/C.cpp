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
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
////////////////////////////////////////////////////////////////////////////////////////////////////////

using mint = modint1000000007;

mint dp[1010101][4];
int main(){
    int n; cin >> n;

    dp[0][0] = 1;
    rep(i, n){
        rep(j, 10){
            if(j==0){
                dp[i+1][1] += dp[i][0] + dp[i][1];
                dp[i+1][3] += dp[i][2] + dp[i][3];
            }
            else if(j==9){
                dp[i+1][2] += dp[i][0] + dp[i][2];
                dp[i+1][3] += dp[i][1] + dp[i][3];
            }
            else{
                rep(k, 4)dp[i+1][k] += dp[i][k];
            }
        }
    }
    cout << dp[n][3].val() << ln;
}
