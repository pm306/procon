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
自分の解法
番兵を左右に配置してバグを防いでいる
*/

int main(){
    int n; cin >> n;
    vector<ll> A(n); rep(i, n) cin >> A[i];

    //番兵
    A.push_back(-INF);
    A.push_back(INF);
    sort(all(A));

    int q; cin >> q;
    vector<ll> ans;
    while(q--){
        int b; cin >> b;
        auto it = lower_bound(all(A), b);
        ll x = *it--, y = *it;
        ll res = min(abs(x-b), abs(y-b));
        ans.push_back(res);
    }
    fore(a, ans)cout << a << ln;
}
