#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
典型中の典型
*/

int dp[123][12345]; //i問目まで見て、j点になるかどうか
int main(){
    int N; cin >> N;

    dp[0][0] = true;
    rep(i, N){
        int a; cin >> a;
        rep(j, 10000){
            if(!dp[i][j])continue;
            dp[i+1][j+a] = true;
            dp[i+1][j] = true;
        }
    }
    cout << accumulate(dp[N], dp[N]+10001, 0) << ln;
}
