#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
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

int main(){
    int N; cin >> N;

    vector<int> memo(N+1, -1);
    auto dp = [&](auto dp, int v) -> int{
        if(v == 0)return 0;

        if(memo[v] != -1)return memo[v];

        int ret = dp(dp, v-1) + 1;
        for(int i=6; v-i>=0; i*=6)chmin(ret, dp(dp, v-i) + 1);
        for(int i=9; v-i>=0; i*=9)chmin(ret, dp(dp, v-i) + 1);

        return memo[v] = ret;
    };
    cout << dp(dp, N) << ln;
}

