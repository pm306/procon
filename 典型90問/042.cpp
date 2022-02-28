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

using mint = modint1000000007;

//dp[i]:=桁和がiである正の整数の数
//ans:dp[K]
//初期値dp[0]=1
//遷移dp[i+1]~dp[i+9] += dp[i]
int main(){
    int K; cin >> K;

    if(K%9){
        cout << 0 << ln;
        return 0;
    }

    vector<mint> memo(K+1);
    auto dp = [&](auto dp, int n)->mint{
        if(n == 0)return (mint)1;

        if(memo[n] != 0)return memo[n];

        mint ret = 0;
        for(int i=n-1; i>=max(0, n-9); i--){
            ret += dp(dp, i);
        }
        return memo[n] = ret;
    };

    cout << dp(dp, K).val() << ln;
}

