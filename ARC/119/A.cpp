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
全探索系。
パっと見手を付けづらい。

典型[パターンの少ない変数を固定して考える]
bは高々60通り程度しかない。
bが決まった時、b>=1なので、a+b<=Nの範囲でaを最大にするのが最善。
cは自動的に決まる。
*/


int main(){
    ll N; cin >> N;

    ll res = LINF;
    for(int i=0; i<=60; i++){
        ll tmp = pow(2, i);
        ll max_a = N / tmp;
        ll c = N % tmp;
        chmin(res, max_a + i + c);
    }
    cout << res << ln;
}
