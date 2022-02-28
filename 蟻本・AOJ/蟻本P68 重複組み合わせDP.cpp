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

/*
https://scrapbox.io/pocala-kyopro/%E8%9F%BB%E6%9C%AC_p.67
遷移の高速化テク

*/

int main(){
    const int N = 3, M = 3;
    vector<int> a{1,2,3};

    //dp[i][j]:=先頭からi個見てj個選んだ時の組み合わせ
    int dp[N+1][M+1]{};
    //1つも選ばない
    rep(i, N+1)dp[i][0] = 1;

    rep(i, N){
        rept(j, 1, M+1){
            if(j-a[i]-1 >= 0){
                dp[i+1][j] = dp[i+1][j-1] + dp[i][j] - dp[i][j-a[i]-1];
            }
            else{
                dp[i+1][j] = dp[i+1][j-1] + dp[i][j];
            }
        }
    }
    cout << dp[N][M] << ln;
}
