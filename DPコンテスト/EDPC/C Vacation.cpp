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
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N;
int P[101010][3], memo[101010][3];

//dp[i][j]:=i日目まで行動を終え、最終日に取った行動がactである時の最大幸福度
int dp(int n, int act){
    if(n < 0)return 0;

    if(memo[n][act] != -1)return memo[n][act];

    int ret = 0;
    for(int i=0; i<3; i++){
        if(i==act)continue;//前日と同じ行動は取れない
        chmax(ret, dp(n-1, i) + P[n][act]);
    }
    return memo[n][act] = ret;
}

int main(){
    cin >> N;
    rep(i, N)rep(j, 3)cin >> P[i][j];

    memset(memo, -1, sizeof(memo));

    int res = 0;
    rep(i, 3)chmax(res, dp(N-1, i));
    cout << res << ln;
}

