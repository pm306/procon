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
二分探索 + 端から貪欲に詰める
判定パートに考察が必要。
*/

int main(){
    int n, m; cin >> n >> m;
    ll X[101010]; rep(i, m)cin >> X[i];

    auto check = [&](ll x) -> bool{
        ll right = 1; //未清掃の最右マス
        rep(i, m){
            chmin(right, X[i]);

            ll must = X[i] - right; //必ず移動しなければならないマスの数
            if(x < must)return false;
            ll a = (x - must) / 2;
            ll b = x - must * 2;
            right = X[i] + max(a, b) + 1;
        }
        return right > n;
    };

    ll lo = -1, hi = INF;
    while(hi - lo > 1){
        ll mid = (hi + lo) / 2;
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << ln;
}
