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

/*
求める答えがdpの中身そのものではなく
終着点のうち、X以下の条件を満たす最大値
この場合は再帰で書かないほうが良いと思う
(再帰で引っ張ってこようとすると、いらん値が引っ張られる)
*/

int N, W;
ll weight[110], val[110], memo[110][101010];

//dp[i][v]:=i番目以降の品物を最適に選んで、価値がv以下になる時の重さの最小値
ll dp(int n, int v){
    //ベースケース
    if(n == N)return 0;

    if(memo[n][v] != INF)return memo[n][v];

    ll ret = INF;
    //i番目の品物を選ぶ
    if(v-val[n] >= 0)chmin(ret, dp(n+1, v - val[n]) + weight[n]);
    //i番目の品物をを選ばない
    chmin(ret, dp(n+1, v));

    return memo[n][v] = ret;
}

int main(){
    cin >> N >> W;
    rep(i, N)cin >> weight[i] >> val[i];

    rep(i, 110)rep(j, 101010)memo[i][j] = INF;

    cout << dp(0, 100000) << ln;
}
