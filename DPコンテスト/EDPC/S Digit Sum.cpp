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

using mint = modint1000000007;

mint dp[101010][2][101];
int main(){
    string s; int d; cin >> s >> d;
    int n = s.size();

    dp[0][0][0] = 1;
    rep(i, n){
        rep(smaller, 2){
            rep(j, d){
                for(int k=0; k<=(smaller ? 9 : (s[i]-'0')); k++){
                    dp[i+1][smaller | k < (s[i]-'0')][(j+k)%d] += dp[i][smaller][j];
                }
            }
        }
    }
    cout << (dp[n][0][0] + dp[n][1][0] - 1).val() << ln;
}
