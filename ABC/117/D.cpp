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
Q:桁DPしたいんだけど、入力値の桁数が不定の場合はどうするの？
A:大きい方の桁は0埋めされてると考えると、桁数を固定できるのじゃ！（天才）

*/

ll dp[100][2]; //dp[i][smaller]:=ビット列を前から見て、下からi桁目までを見た時の、f(x)の最大値
int main(){
    int N; ll K; cin >> N >> K;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    rep(i, 100)dp[i][0] = dp[i][1] = -1;
    dp[45][0] = 0;
    for(int d=44; d>=0; d--){
        ll mask = 1ll<<d;
        int num = 0; //d桁目の立っているビットの数
        rep(i, N)if(A[i]&mask)num++;

        //from smaller
        if(dp[d+1][true] >= 0)chmax(dp[d][true], dp[d+1][true] + mask * (max(num, N-num))); //0or1を選択
        //not smaller
        if(dp[d+1][false] >= 0){
            //捜査中、初めてビット列が立った場合
            if(K & 1ll<<d){
                chmax(dp[d][true], dp[d+1][false] + mask * num); //0を選択
                chmax(dp[d][false], dp[d+1][false] + mask * (N-num));//1を選択
            }
            //まだ1度もビット列が立たない場合
            else{
                chmax(dp[d][false], dp[d+1][false] + mask * num);
            }
        }
    }
    cout << max(dp[0][0], dp[0][1]) << ln;
}

