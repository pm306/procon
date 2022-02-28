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
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
-1 <= y2-y1 / x2-x1 <= 1
↓
|y2-y1| <= |x2-x1|
×
-a <= b <= a
なんで？ -> 式変形が間違ってる
不等式の式変形
https://systemath.jp/hutosiki-sesitu/#i-3
両辺に負の実数をかけたり割ったりすると、不等号の向きが逆転する

傾きをb/aとして
a = x2 - x1(x2 > x1)
とすると、必ずaは正になることを利用する
お気持ちとしては、2点のペアを選ぶときに、ｘが大きい方を右側に配置する

*/

int main(){
    int n; cin >> n;
    vector<ll> X(n), Y(n); rep(i, n)cin >> X[i] >> Y[i];

    int res = 0;
    rep(i, n){
        rept(j, i+1, n){
            ll b = Y[j]-Y[i], a = X[j]-X[i];
            if(abs(b) <= abs(a))res++;
        }
    }
    cout << res << ln;
}


