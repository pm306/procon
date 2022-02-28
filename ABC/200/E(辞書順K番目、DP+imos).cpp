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
辞書順でK番目のものを答えよ、という問題と同様の解き方で解く（あってた）
どうやってsumごとの組み合わせ数を数えるか⇒DP+いもす法（わからなかった）
Nが変動して貪欲できないのでDPという発想が自然かもしれない
*/

ll dp[4][3010101];
int main(){
    ll N, K; cin >> N >> K;

    dp[0][0] = 1;
    rep(cnt, 3){
        rep(sum, 2010101){ //何故2*1e6なのか？ -> dp[2][sum]の最大値が200000だから
            //imos法
            dp[cnt+1][sum+1] += dp[cnt][sum];
            dp[cnt+1][sum+N+1] -= dp[cnt][sum];
        }
        rept(sum, 1, 3010101){
            dp[cnt+1][sum] += dp[cnt+1][sum-1];
        }
    }

    ll cu = 1;//今見てるのが何番目か？
    //総和を確定させる
    int sum = -1; //3つの数の総和。最大1e6*3
    for(int i=3; i<3010101; i++){
        if(cu <= K and K < cu + dp[3][i]){//グループの範囲内かどうか
            sum = i;
            break;
        }
        cu += dp[3][i];
    }

    rep(i, sum) K -= dp[3][i]; //総和未満のグループ合計値を引く

    cu = 1;
    int ans_a = -1;
    //aを全探索
    rept(a, 1, N+1){
        if(cu <= K and K < cu + dp[2][sum - a]){ //dp[2][sum-a]:aを固定してb,cを選んだときの総和の場合の数
            ans_a = a;
            break;
        }
        cu += dp[2][sum-a];
    }

    rept(i, 1, ans_a) K -= dp[2][sum - i];

    cu = 1;
    int ans_b = -1;
    //bを全探索
    rept(b, 1, N+1){
        if(cu <= K and K < cu + dp[1][sum - ans_a - b]){
            ans_b = b;
            break;
        }
        cu += dp[1][sum - ans_a - b];
    }

    int ans_c = sum - ans_a - ans_b;
    cout << ans_a << " " << ans_b << " " << ans_c << ln;
}
