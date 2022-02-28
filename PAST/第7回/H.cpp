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

double calclen(int a, int b){
    return sqrt(1 + abs(a-b) * abs(a-b));
}

double dp[110][110][110]; //前iマス見て、合計j個の石を置いて最後がk個の時の最小スコア
int main(){
    int n; cin >> n;
    int sum = 0;
    rep(i, n){
        int a; cin >> a;
        sum += a;
    }

    rep(i,110)rep(j, 110)rep(k, 110)dp[i][j][k] = INF;
    dp[1][0][0] = 0.0;
    for(int i=1; i<n; i++){
        //石を置いてきた個数
        for(int j=0; j<=sum; j++){
            //最後に置いた石がk個のときから遷移
            for(int pre=0; pre<=sum; pre++){
                if(dp[i][j][pre] == INF)continue;
                //次に置く石の数を決める
                for(int nx=0; nx<=sum; nx++){
                    if(i==n-1 and nx)continue; //最後のマスには石を置けない
                    if(j + nx > sum)continue;//そんなに石を置けない
                    chmin(dp[i+1][j+nx][nx], dp[i][j][pre] + calclen(pre, nx));
                }
            }
        }
    }

    cout << fixed << setprecision(12);
    cout << dp[n][sum][0] << ln;
}

