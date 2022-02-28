#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1<<30;
constexpr long long LINF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
bitDP
問題を、N頂点の完全グラフのうち、条件を満たすハミルトン路の数を数える問題と言い換えるとイメージしやすいか。
集合の要素数は__builtin_popcountで取得できる

条件判定
要素数がX[i]の時だけ判定する　条件を毎回全部見てもMが小さいので間に合う
下からY[i]個のビットを見てZ[i]個以下かどうか判定する
*/

ll X[110], Y[110], Z[110], dp[1<<18];
int main(){
    int N, M; cin >> N >> M;
    rep(i, M)cin >> X[i] >> Y[i] >> Z[i];

    dp[0] = 1;
    for(int mask=1; mask<1<<N; mask++){
        int popcnt = __builtin_popcount(mask);
        bool fg = true;
        rep(i, M){
            if(X[i]!=popcnt)continue;
            int cnt = 0;
            rep(j, Y[i]){
                if(mask>>j&1)cnt++;
            }
            if(cnt > Z[i])fg = false;
        }
        if(fg){
            for(int from=0; from<N; from++){
                if(mask>>from&1){
                    dp[mask] += dp[mask^1<<from];
                }
            }
        }
    }
    cout << dp[(1<<N)-1] << ln;
}
