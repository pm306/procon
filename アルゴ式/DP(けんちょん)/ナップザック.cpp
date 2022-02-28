#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(){
    int N, W; cin >> N >> W;
    vector<int> weight(N), val(N); rep(i, N)cin >> weight[i] >> val[i];

    //前からi個見て残り容量がw
    vector memo(N+1, vector<int>(W+1, -1));
    auto dp = [&](auto dp, int i, int w) -> int{
        if(w < 0)return -(1<<30);
        if(i == N)return 0;

        if(memo[i][w] != -1)return memo[i][w];

        int ret = max(dp(dp, i+1, w), dp(dp, i+1, w-weight[i]) + val[i]);
        return memo[i][w] = ret;
    };
    cout << dp(dp, 0, W) << ln;
}
