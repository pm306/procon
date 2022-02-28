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
シミュレート系
累積和
漸化式の差に注目する
現時点までの最大値をメモ化しながら進む
*/

int main(){
    int n; cin >> n;
    vector<ll> A(n), S(n+1);
    rep(i, n){
        cin >> A[i];
        S[i+1] = S[i] + A[i]; //累積和
    }

    //pos:各動作前の座標、ma:S[0]~S[i]の最大値
    //MAX[i] = pos + max(max(S[0]~S[i]), S[i])
    ll pos = 0, ma = -LINF;
    ll res = pos; //初期位置が最大値のパターンもあるので0で初期化
    rep(i, n){
        chmax(ma, S[i]);
        chmax(res, pos+max(ma, S[i+1]));
        pos += S[i+1];  //現在地の更新を忘れずに
    }
    cout << res << ln;
}   