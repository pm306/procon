#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
編集距離、LCSの応用問題
テーブルの定義が難しかった
「条件を満たす（長さが同じになるようにする）最小コスト」でOK
長さが同じ？どうやってやるの？　と思うが
動的計画法は１文字ずつ遷移するので増えた分を消せば良いだけだった
dp[0][0]が確定して、そこから少しずつ枝を伸ばしていくようなイメージ
*/

int main(){
    int n, m; cin >> n >> m;
    vector<int> A(n), B(m);
    rep(i, n)cin >> A[i];
    rep(i, m)cin >> B[i];

    //テーブルを大きめに持ってif文を省略
    vector<vector<ll>> dp(n+10, vector<ll>(m+10, LINF));
    dp[0][0] = 0;
    rep(i, n+1){
        rep(j, m+1){
            //1文字加えた処理を分岐させて整合性を保つ

            //Aの末尾を削除する
            chmin(dp[i+1][j], dp[i][j]+1);
            //Bの末尾を削除する
            chmin(dp[i][j+1], dp[i][j]+1);
            //削除せず、両方追加する
            if(A[i]==B[j]){
                chmin(dp[i+1][j+1], dp[i][j]);
            }else{
                chmin(dp[i+1][j+1], dp[i][j]+1);
            }
        }
    }
    cout << dp[n][m] << ln;
}   