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

const int MAX = 10010;
ll dp[MAX]; //与えたダメ―ジの合計がiの時の最小消費魔力
int main(){
    ll h, n; cin >> h >> n;
    fill(dp, dp+MAX, LINF); dp[0] = 0;

    rep(i, n){
        ll a, b; cin >> a >> b;
        rep(j, h){
            if(dp[j]==LINF)continue;
            chmin(dp[min(h, j+a)], dp[j] + b); //ダメージがＨを超える場合はdp[h]に格納する
        }
    }
    cout << dp[h] << ln;
}

// 問題文は「N種類の魔法から好きな魔法を好きなだけ選んで、ダメージがH以上になったときのBの最小値を求めよ」と言い換えられる
// 条件が以下から以上、求める値が最大値から最小値になっただけで、題意は個数制限ナップザックそのもの
// ナップザックDPは一次元にまとめられるのでそうしているが、別に二次元でも解ける（一次元のほうが実装が楽で速い）

