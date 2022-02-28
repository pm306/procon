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
直観的に解けばOK
*/

using mint = modint1000000007;

mint dp[1010][1010];
int main(){
    int H, W; cin >> H >> W;
    vector<string> g(H); rep(i, H)cin >> g[i];

    dp[0][0] = 1;
    rep(i, H){
        rep(j, W){
            if(g[i][j] == '#')continue;
            if(j < W-1 and g[i][j+1] != '#'){
                dp[i][j+1] += dp[i][j];
            }
            if(i < H-1 and g[i+1][j] != '#'){
                dp[i+1][j] += dp[i][j];
            }
        }
    }
    cout << dp[H-1][W-1].val() << ln;
}

