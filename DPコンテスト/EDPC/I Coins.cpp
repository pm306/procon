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
状態を2つ持つDP
状態１つだと、次に裏が出たときでもまだ表のほうが多いかどうかがわからないからうまくいかない

//漸化式をきちんと整理すれば解けるよ～ん

//コインをi枚投げ終えた時、表がj枚である確率
dp[i][j] = dp[i-1][j-1] * p[i-1](表) + dp[i-1][j] * (1-p)(裏)
*/

double dp[3030][3030];
int main(){
    int N; cin >> N;
    vector<double> P(N); rep(i, N)cin >> P[i];

    dp[0][0] = 1.0;
    rep(i, N){
        rep(j, N+1){
            if(j)dp[i+1][j] += dp[i][j-1] * P[i]; //表
            dp[i+1][j] += dp[i][j] * (1.0 - P[i]); //裏
        }
    }
    double res = 0.0;
    for(int i=N/2+1; i<=N; i++){
        res += dp[N][i];
    }
    cout << fixed << setprecision(12);
    cout << res << ln;
}

