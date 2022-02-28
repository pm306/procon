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
dp[i][j]:=i番目まで見て、最後に見た値がjである場合の最高スコア
というテーブルを作りたくなる。
しかし、
・配列でかすぎ問題
・漸化式わからない、わかっても計算量でかそう。遷移１つでもテーブルでかすぎてO(N^2)不可避
という２つの問題が出て詰まった。

という問題があった

------------------------------------------
・テーブルの立て方自体は合ってる。

・漸化式(遷移)をよく考えてみる
dp[i][j]:=最後に見た値が[j]である、としている
ので、各iについて1箇所だけ更新(H[i]を採用するケース)が起こり、それ以外は状態を引き継ぐことになる
この「1箇所だけ更新、残りは状態引継ぎ」がキモ……かもしれない
状態を引き継ぐとしても結局O(N^2)かかりそうだが、実はテーブルを削減することで
・テーブルサイズ
・引継ぎの計算
が両方削減できてしまう！

よってテーブルおよび計算量問題が一気に解決した。削減すごい。

・漸化式
各iについて、dp[H[i]]のみ更新が起こる。
dp[H[i]] = max(dp[i-1][k])(k:=0~H[i]-1)
H[i]より小さな遷移元から最大のものを選ぶ必要があるが、これは区間最大値であり、セグメントツリーを使うことで高速遷移ができる。（天才）
よって、遷移の問題も解決した

「最後に使用した値がｊである」っていう定義がミソだなあ
確かに最後以外は要らないしね
こうすることで要素1個の遷移が1回になる
*/

ll op(ll a, ll b){return max(a, b);}
ll e(){return -1;}

int main(){
    int N; cin >> N;
    ll H[202020], A[202020]; rep(i, N)cin >> H[i]; rep(i, N)cin >> A[i];

    segtree<ll, op, e> dp(N+1);
    dp.set(0, 0);

    rep(i, N){
        ll max_val = dp.prod(0, H[i]);
        dp.set(H[i], max(dp.get(H[i]), max_val + A[i]));
    }

    cout << dp.prod(0, N+1) << ln;
}
