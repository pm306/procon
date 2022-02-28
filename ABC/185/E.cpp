#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n, m; cin >> n >> m;
    vector<int> A(n), B(m);
    rep(i, n)cin >> A[i];
    rep(i, m)cin >> B[i];

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, LINF));
    dp[0][0] = 0;
    rep(i, n+1){
        rep(j, m+1){
            if(i>0){
                chmin(dp[i][j], dp[i-1][j]+1);
            }
            if(j>0){
                chmin(dp[i][j], dp[i][j-1]+1);
            }
            if(i>0 and j>0){
                int cost = A[i-1]==B[j-1] ? 0 : 1;
                chmin(dp[i][j], dp[i-1][j-1]+cost);
            }
        }
    }
    cout << dp[n][m] << ln;
}   