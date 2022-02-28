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

ll dp[100][2];
int main(){
    int n; cin >> n;
    vector<string> logs(n); rep(i, n)cin >> logs[i];

    dp[0][0] = dp[0][1] = 1;
    rep(i, n){
        if(logs[i]=="AND"){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][0] + dp[i][1]*2;
        }else{
            dp[i+1][1] = dp[i][1];
            dp[i+1][0] = dp[i][1] + dp[i][0]*2;
        }
    }
    cout << dp[n][0] << ln;
}
