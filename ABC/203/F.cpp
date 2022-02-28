#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[33][202020];
int main(){
    int N, K; cin >> N >> K;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }
    rep(i, 33)rep(j, 202020)dp[i][j] = LINF;
    dp[0][0] = 0;

    sort(all(A));
    for(int i=0; i<=30; i++){
        for(int j=0; j<N; j++){
            //高橋君が操作しない
            chmin(dp[i][j+1], dp[i][j] + 1);
            //高橋君が操作する
            int next = (A.end() - j) - lower_bound(all(A), A[N-j-1]/2 + 1);
            chmin(dp[i+1][j+next], dp[i][j]);
        }
    }

    for(int i=0; i<=30; i++){
        if(dp[i][N]<= K){
            cout << i << " " << dp[i][N] << ln;
            break;
        }
    }
}
