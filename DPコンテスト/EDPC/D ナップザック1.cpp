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

//dp(i, w):=i番目以降の品物を確認し、ナップザックの許容量がwである時の最大価値
int N, W;
ll weight[110], val[110], memo[110][101010];

ll dp(int n, int w){
    //ベースケース 0個の品物から選ぶので、常に価値は0
    if(n == N)return 0;

    if(memo[n][w] != -1)return memo[n][w];

    ll ret = 0;
    //n番目の品物を選ぶ
    if(w-weight[n]>=0)chmax(ret, dp(n+1, w-weight[n]) + val[n]);
    //n番目の品物を選ばない
    chmax(ret, dp(n+1, w));

    return memo[n][w] = ret;
}

int main(){
    cin >> N >> W;
    rep(i, N)cin >> weight[i] >> val[i];

    memset(memo, -1, sizeof(memo));

    cout << dp(0, W) << ln;
}

