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
二分探索 + 数学的考察
作る花束ではなく、花ごとに必要本数を見積もって考える。
*/


int main(){
    ll R, B, x, y; cin >> R >> B >> x >> y;

    auto check = [&](ll val) -> bool{
        if(R - val < 0 or B - val < 0)return false;
        return (R - val) / (x - 1) + (B - val) / (y - 1) >= val;
    };

    ll lo = 0, hi = INF;
    while(hi - lo > 1){
        ll mid = (hi + lo) / 2;
        if(check(mid))lo = mid;
        else hi = mid;
    }
    cout << lo << ln;
}

