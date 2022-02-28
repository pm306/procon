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

using mint = modint998244353;

mint dp[1010][1100][11];
int main(){
    int n; string s; cin >> n >> s;

    dp[0][0][10] = 1;
    for(int i=0; i<n; i++){
        for(int S=0; S<1<<10; S++){
            for(int k=0; k<11; k++){
                //次のコンテストに出ない
                dp[i+1][S][k] += dp[i][S][k];
                //次のコンテストに出る
                int nxcon = (s[i] - 'A');
                if(S>>nxcon&1)continue;
                if(k == 10){
                    dp[i+1][0][nxcon] += dp[i][S][k];
                }
                else if(k == nxcon){
                    dp[i+1][S][k] += dp[i][S][k];
                }
                else{
                    dp[i+1][S | (1<<k)][nxcon] += dp[i][S][k];
                }
            }
        }
    }

    mint res = 0;
    rep(S, 1<<10)rep(k, 10)res += dp[n][S][k];
    cout << res.val() << ln;
}
