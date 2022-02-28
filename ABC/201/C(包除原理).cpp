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
別解
問題文を以下のように言い換える
条件Ai:=パスワードに必ずiを含む
として
Ai1 and Ai2 and ... and Ain
条件が「１回以上」となっているのが面倒なので、余事象を考えてみる
not Ai:=パスワードにAiを含まない
含まないならoをxに言い換えられるので、数え上げが楽になる
notAi1 or notAi2 or ... or notAin
orの条件なので包除原理を適用する
oと?である数からoをi個選んでxに塗り替えた場合の数は
comb(o, i) * pow(q + (o - i), 4)
となり高速に求められる

*/

int fact(int n){
    return n == 0 ? 1 : fact(n-1) * n;
}
int nCr(int n, int r){
    return fact(n) / fact(r) / fact(n - r);
}

int main(){
    string S; cin >> S;
    int L = 4;
    int o = count(all(S), 'o'), q = count(all(S), '?');

    int res = 0;
    //包除原理。余事象をあらかじめ正負反転して計算している
    //i==o:S(全事象:o+?種類の数字を使う組み合わせの数)
    rep(i, o+1){
        int ans = pow(-1, o-i) * nCr(o, i) * pow(q+i, L);
        res += ans;
    }
    cout << res << ln;
}
