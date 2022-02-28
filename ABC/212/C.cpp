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
////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(){
    int n, m; cin >> n >> m;
    vector<ll> A(n), B(m);
    rep(i, n)cin >> A[i];
    rep(i, m)cin >> B[i];

    B.push_back(-INF);
    B.push_back(INF);
    sort(all(B));

    ll res = INF;
    fore(a, A){
        auto it = lower_bound(all(B), a);
        ll ans1 = abs(*it - a);
        it--;
        ll ans2 = abs(*it - a);
        chmin(res, min(ans1, ans2));
    }
    cout << res << ln;
}

