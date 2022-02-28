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
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
a,b,cの値が不定かつ幅広いので、貪欲法やdpは使えなさそう。

「合計10000枚未満で必ず払える」制約を利用する
*/

int main(){
    ll n, a, b, c; cin >> n >> a >> b >> c;

    ll res = INF;
    for(int i=0; i<10000; i++){
        for(int j=0; i+j<10000; j++){
            ll sum = a * i + b * j;
            if(sum > n)continue;
            if((n - sum) % c)continue;
            ll k = (n - sum) / c;
            chmin(res, i + j + k);
        }
    }
    cout << res << ln;
}
