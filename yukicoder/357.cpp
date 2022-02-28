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


int main(){
    ll N, M; cin >> N >> M;
    ll A[300][300]{};rep(i, M){int a, b, s; cin >> a >> b >> s; A[a][b] = s;}

    //dp[S]:= 選んだ品物の集合がSである時の得点の最大値
    vector<ll> dp(1<<N);
    rep(mask, 1<<N)rep(i, N)if(!(mask>>i&1)){
        ll add = 0;
        rep(j, N)if(mask>>j&1)add += A[j][i];
        chmax(dp[mask+(1<<i)],dp[mask] + add);
    }
    cout << dp[(1<<N)-1] << ln;
}
