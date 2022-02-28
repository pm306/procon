#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
区間DPの一種？
最初の一人の金貨は固定だけど、それ以降はわからねーじゃん
→区間が分断されて独立するので、再帰的に必要量を求められる
という発想
最初のひとりの解放に必要な量は不変なので、区間を全探索できる
*/

const int MAX_Q = 100;
int P, Q, A[MAX_Q+2];

//dp[i][j];=i人目の囚人からj人目の囚人まで(両端は含まない)を解放するのに必要な金貨の最小枚数
int dp[MAX_Q+1][MAX_Q+2];

void solve(){
    //簡単のため、端をAに追加する
    A[0] = 0;
    A[Q+1] = P + 1;

    //init
    rep(i, Q+1)dp[i][i+1] = 0;

    //幅
    for(int w=2; w<=Q+1; w++){
        //左端
        for(int i=0; i+w<=Q+1; i++){
            int j=i+w;//右端
            cout << "i:" << i << " j:" << j << ln;

            int t = INF; //2番目以降で解放に必要な金貨
            for(int k=i+1; k<j; k++){
                 t = min(t, dp[i][k] + dp[k][j]);
            }
            //i-j間の1人目の囚人を解放するには必ずA[j]-A[i]-2枚必要
            dp[i][j] = t + A[j] - A[i] - 2;
        }
    }
    cout << dp[0][Q+1] << ln;
}

int main(){
    cin >> P >> Q;
    rep(i, Q) cin >> A[i+1];
    solve();
}

