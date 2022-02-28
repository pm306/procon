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
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
部分列DPのド典型
*/


//Sのi文字目以降で最初に文字が登場するindex 登場しないならlen(s)を返す
vector<vector<int>> calcNextIndex(string &S){
    int n = S.size();
    vector<vector<int>> ret(n+1, vector<int>(26, n));
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<26; j++)ret[i][j] = ret[i+1][j];
        ret[i][S[i]-'a'] = i;
    }
    return ret;
}

using mint = modint1000000007;

int main(){
    string s; cin >> s;
    int n = s.size();

    auto next = calcNextIndex(s);
    vector<mint> dp(n+1);
    dp[0] = 1;
    rep(i, n)rep(j, 26){
        if(next[i ? i+1 : i][j] >= n)continue;
        dp[next[i ? i+1 : i][j] + 1] += dp[i];
    }

    mint res = 0;
    rep(i, n+1)res += dp[i];
    if(n > 1)res--;
    cout << res.val() << ln;
}

