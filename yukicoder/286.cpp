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
    //dp[S]:=購入した商品の集合がSの場合、最小購入金額

    ll N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    vector<ll> dp(1<<N, LINF);
    dp[0] = 0;
    rep(mask, 1<<N)rep(i, N)if(!(mask>>i&1)){
        ll sum = 0;
        rep(j, N)if(mask>>j&1)sum += A[j];
        chmin(dp[mask + (1<<i)], dp[mask] + max(0LL, A[i] - sum % 1000));
    }
    cout << dp[(1<<N)-1] << ln;
}
