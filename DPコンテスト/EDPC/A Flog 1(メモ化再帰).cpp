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

//dp[i]:=頂点iにいる時の最小コスト
//求めたい値:dp[N-1]
//初期値:dp[0] = 0
//遷移:dp[i] = min(dp[i-1], dp[i-2])
//計算量:N(状態数) * 2(遷移数) = O(N)

int N;
int H[101010], memo[101010];
int dp(int v){
    if(v == 0)return 0;

    if(memo[v] != -1)return memo[v];

    int ret = 1<<30;
    chmin(ret, dp(v-1) + abs(H[v] - H[v-1]));
    if(v-2 >= 0)chmin(ret, dp(v-2) + abs(H[v] - H[v-2]));

    return memo[v] = ret;
}

int main(){
    cin >> N;
    rep(i, N)cin >> H[i];

    memset(memo, -1, sizeof(memo));

    cout << dp(N-1) << ln;
}

