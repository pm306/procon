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

ll S[20][101010];
int main(){
    int N, M; cin >> N >> M;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    //累積和 S[i][j]:=i種類のぬいぐるみが前j個に何個出てきたか
    rep(i, M)rep(j, N) S[i][j+1] = S[i][j] + (A[j]==i+1 ? 1 : 0);

    //dp[S]:=位置を決めたぬいぐるみ種類の集合がSである時の、動かすべきぬいぐるみの最小数
    vector<ll> dp(1<<M, LINF);
    dp[0] = 0;
    rep(mask, 1<<M)rep(i, M)if(!(mask>>i&1)){
        ll idx = 0;
        rep(j, M)if(mask>>j&1)idx += S[j][N];
        ll add = 0;
        rep(j, M)if(j != i)add += S[j][idx+S[i][N]] - S[j][idx];
        chmin(dp[mask+(1<<i)], dp[mask] + add);
    }
    cout << dp[(1<<M)-1] << ln;
}
