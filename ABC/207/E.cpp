#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using mint = modint1000000007;

mint dp[3010][3010]; //dp[i][k] := i番目まででk組作った
mint tot[3010][3010]; //tot[k][mo] := k組作っていて、これまでの総和を(k+1)で割った余りがmoである

int main(){
    int N; cin >> N;
    ll A[3010]; rep(i, N)cin >> A[i];

    dp[0][0] = 1;
    tot[0][0] = 1;
    ll sum = 0;
    rep(i, N){
        sum += A[i];
        rept(k, 1, N+1)dp[i+1][k] = tot[k-1][sum % k];
        rept(k, 1, N+1)tot[k][sum % (k+1)] += dp[i+1][k];
    }

    mint res = 0;
    rept(k, 1, N+1)res += dp[N][k];
    cout << res.val() << ln;
}

