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
素朴なLISのアルゴリズム(蟻本:P64)
dp[i]:=先頭i項見て、数列の最後がA[i]であるような最長の部分増加列の長さ
初期化:dp[i] = 1 //その数字のみを採用した場合
漸化式:dp[i] = max(dp[j]+1) ※j<iかつ,A[j]<A[i]。A[j]のおしりにA[i]をくっつけるイメージ
計算量:O(N^2) バブルソートのイメージするとわかりやすいかも
*/

int main(){
    int N = 5;
    vector<int> A = {4,2,3,1,5};

    vector<int> dp(N+1);
    int res = 0;
    for(int i=0; i<N; i++){
        dp[i] = 1;//A[i]を先頭にする
        for(int j=0; j<i; j++){
            //自分より前の項を見て、末尾にくっつけられそうならくっつける
            if(A[j] < A[i])chmax(dp[i], dp[j] + 1);
        }
        chmax(res, dp[i]);
    }
    cout << res << ln;
}
