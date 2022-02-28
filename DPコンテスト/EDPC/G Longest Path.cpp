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
DAG上の最長パスを求める問題。
葉から再帰的に問題を解くことによって、全体の最大値が求まる。
各頂点に大して一度しか探索しないので、計算量O(N+M)

再帰dpの練習に丁度良い問題
*/

int main(){
    int N, M; cin >> N >> M;
    vector<vector<int>> g(N);
    rep(i, M){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
    }

    //dp[v]:= 頂点vからの最長パスを返す
    vector<int> memo(N, -1);
    auto dp = [&](auto dp, int v) -> int{
        //ベースケース
        if(g[v].size() == 0)return 0;

        if(memo[v] != -1)return memo[v];

        int ret = 0;
        fore(to, g[v]){
            chmax(ret, dp(dp, to) + 1);
        }
        return memo[v] = ret;
    };

    int res = 0;
    rep(i, N){
        if(memo[i] != -1)continue; //探索済み
        chmax(res, dp(dp, i));
    }
    cout << res << ln;
}

