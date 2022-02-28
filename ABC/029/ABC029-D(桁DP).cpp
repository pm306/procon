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

/*
1がj回出現した数の個数を桁DPでまとめて数える
答えは1の個数なので、復元処理を忘れずに
*/

//i桁目まで見て、1がj回出現した値の個数
ll dp[20][2][20];
int main(){
    string N; cin >> N;
    int n = N.size();

    dp[0][0][0] = 1;
    rep(i, n){
        rep(smaller, 2){
            rep(j, 15){
                for(int x=0; x<=(smaller ? 9 : N[i]-'0'); x++){
                    dp[i+1][smaller or x<N[i]-'0'][x==1 ? j+1 : j] += dp[i][smaller][j];
                }
            }
        }
    }
    ll res = 0;
    rept(i, 1, 15){
        res += (dp[n][0][i] + dp[n][1][i]) * i;
    }
    cout << res << ln;
}
