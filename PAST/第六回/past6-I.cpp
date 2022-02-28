#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[110][110][220], A[110][110];
int main(){
    int H, W; cin >> H >> W;
    rep(i, H)rep(j, W)cin >> A[i][j];

    //dp[i][j][k]:=区画(i,j)まで来て魚をk匹釣った時の美味しさの最大値
    //遷移:釣るor釣らない,→or↓の4パターン
    rep(i, H){
        rep(j, W){
            rep(k, H+W){
                chmax(dp[i+1][j][k+1], dp[i][j][k] + A[i][j]);
                chmax(dp[i+1][j][k], dp[i][j][k]);
                chmax(dp[i][j+1][k+1], dp[i][j][k] + A[i][j]);
                chmax(dp[i][j+1][k], dp[i][j][k]);
            }
        }
    }
    rept(k, 1, H+W){
        cout << max(dp[H-1][W][k], dp[H][W-1][k]) << ln;
    }
}
