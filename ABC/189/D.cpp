#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 998244353;//1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


//dp[i][j]:=i番目まで見て、j=1ならtrue, 0ならfalseの数
ll dp[66][2];
int main(){
    int N; cin >> N;
    vector<string> S(N); rep(i, N)cin >> S[i];

    dp[0][0] = dp[0][1] = 1;
    rep(i, N){
        rep(j, 2){
            if(S[i]=="AND"){
                rep(k, 2){
                    dp[i+1][j and k] += dp[i][j];
                }
            }
            else{
                rep(k, 2){
                    dp[i+1][j or k] += dp[i][j];
                }
            }
        }
    }
    cout << dp[N][1] << ln;
}

