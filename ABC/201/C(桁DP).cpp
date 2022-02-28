#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//十進数nを二進数で表した時、下からk桁目のビットを返す
int checkBit(ll n, int k){
    return n>>k&1;
}

//dp[i][j]:先頭からi桁目まで見た時、使わなければいけない数字のうち、使われている数字の集合がjである場合の数
int dp[5][1<<10];
int main(){
    string S; cin >> S;

    //桁DP
    dp[0][0] = 1;
    for(int i=0; i<4; i++){
        for(int j=0; j<(1<<10); j++){
            //次に使う値
            for(int n=0; n<10; n++){
                if(S[n]=='x')continue;
                else if(S[n]=='?')dp[i+1][j] += dp[i][j];
                else if(S[n]=='o'){
                    if(checkBit(j, n))dp[i+1][j] += dp[i][j];
                    else dp[i+1][j+(1<<n)] += dp[i][j];
                }
            }
        }
    }
    int s = 0;
    rep(i, 10)if(S[i]=='o')s += (1<<i);
    cout << dp[4][s] << ln;
}
