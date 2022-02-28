#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
自分が自然に書いた場合のコード
【解法】
Kの合計値が属するグループを特定⇒aの属するグループを特定右⇒bの属するグループを特定
動的計画法を高速に動作させることで、値をi個決めて合計がjだった時の組み合わせ数がわかる
グループの特定は、Kから属さないグループを順に引いていくことで求まる
*/

//max(sum(a,b,c))
const int MAX_SUM = 1e6*3+100;

ll dp[4][MAX_SUM];
int main(){
    ll N, K; cin >> N >> K;

    //dp[i][j]:先頭からi番目までの数字を決定したときの、合計値がjである場合の数
    dp[0][0] = 1;
    rep(i, 3){
        rep(j, MAX_SUM){
            if(dp[i][j]==0)continue;
            //imos 前処理
            dp[i+1][j+1] += dp[i][j];
            dp[i+1][j+N+1] -= dp[i][j];
        }
        //imos 同一テーブル上でメモから値を導く
        rept(j,1, MAX_SUM){
            dp[i+1][j] = dp[i+1][j] + dp[i+1][j-1];
        }
    }

    int sum = -1;
    for(int i=3; i<=MAX_SUM; i++){
        if(K <= dp[3][i]){
            sum = i;
            break;
        }
        K -= dp[3][i];
    }
    int ra = -1;
    for(int i=1; i<=N; i++){
        if(K <= dp[2][sum-i]){
            ra = i;
            break;
        }
        K -= dp[2][sum-i];
    }
    int rb = -1;
    for(int i=1; i<=N; i++){
        if(K <= dp[1][sum-ra-i]){
            rb = i;
            break;
        }
        K -= dp[1][sum-ra-i];
    }
    cout << ra << " " << rb << " " << sum-ra-rb << ln;
}
