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
問題を反転？させる
1匹のスライムを分割していくことを考える。
dp[i][j]:=区間[i, j]に相当するスライムが1匹にまとまっている時、それを分解するのに必要な最小コスト

状態数 N^2
初期値:区間[i, i] = 0
遷移:区間を2つに分割(分割統治法？)し、一番良いコストを取得 O(N)

取得したら、2つのスライムを1つに統合する感じでコストを(累積和から)求める

おきもち
dp(l, r):=この区間のスライムをmergeするのに必要なコストっていくつ？
dp(l, k) + dp(k+1, r)[k=l~r-1] 問題を2つに分割する
→最後にマージして、統合コストを加える
*/

int main(){
    int N; cin >> N;
    vector<ll> A(N), S(N+1);
    rep(i, N) cin >> A[i], S[i+1] = S[i] + A[i];

    ll memo[440][440];
    memset(memo, -1, sizeof(memo));
    auto dp = [&](auto dp, int l, int r) -> ll{
        if(l == r)return 0;

        if(memo[l][r] != -1)return memo[l][r];

        ll ret = INF;
        rept(k, l, r){
            chmin(ret, dp(dp, l, k) + dp(dp, k+1, r));
        }
        return memo[l][r] = ret + S[r+1] - S[l];
    };

    cout << dp(dp, 0, N-1) << ln;
}


