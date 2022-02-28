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


int N, W, res;
ll weight[110], val[110], dp[110][101010];

int main(){
    cin >> N >> W;
    rep(i, N)cin >> weight[i] >> val[i];

    rep(i, 110)rep(j, 101010)dp[i][j] = INF;
    dp[0][0] = 0;

    rep(i, N){
        rep(v, N*1010){
            chmin(dp[i+1][v], dp[i][v]);
            chmin(dp[i+1][v+val[i]], dp[i][v]+weight[i]);
        }
    }
    int res = 0;
    rep(v, N*1010)if(dp[N][v]<=W)chmax(res, v);
    cout << res << ln;
}
