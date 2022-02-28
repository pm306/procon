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

//数を1個ずつ決めているわけではない
//その時その時の暫定順位だけに着目している。自身より右側には着目しない
//値を暫定的にセットするイメージ

using mint = modint1000000007;
mint dp[3030][3030];
int main(){
    int n; string s;
    cin >> n >> s;

    //dp[i][j]:= 前からi個見て、最後に選んだ数が下からj番目 の場合の数
    dp[1][1] = 1; //初期値
    for(int i=1; i<n; i++){
        for(int j=1; j<=i; j++){
            //配るDP
            if(s[i-1] == '<'){
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][i+2] -= dp[i][j];
                // for(int k=j+1; k<=i+1; k++){//i個あるところに1個加えるのでk<=i+1
                //     dp[i+1][k] += dp[i][j];
                // }
            }
            else{
                dp[i+1][1] += dp[i][j];
                dp[i+1][j+1] -= dp[i][j];
                // for(int k=1; k<=j; k++){//ぴったりjまで
                //     dp[i+1][k] += dp[i][j];
                // }
            }
        }
        for(int j=0; j<3010; j++){
            dp[i+1][j+1] += dp[i+1][j];
        }
    }
    mint res = 0;
    rep(j, 3030)res += dp[n][j];
    cout << res.val() << ln;
}



