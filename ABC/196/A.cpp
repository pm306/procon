#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
x,yの範囲が指定されるので、x-yの最大値を求めよ

範囲が狭いので全探索する。
*/

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int res = -INF;
    for(int i=a; i<=b; i++){
        for(int j=c; j<=d; j++){
            chmax(res, i-j);
        }
    }
    cout << res << ln;
}
