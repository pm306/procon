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
/////////////////////////////////////////////////////////////////////////////////////////////



int main(){
    int n; cin >> n;

    dsu uf(n);
    vector<tuple<ll, int, int>> vec;
    rep(i, n-1){
       int u, v; ll w; cin >> u >> v >> w; u--, v--;
        vec.emplace_back(w, u, v);
    }
    sort(all(vec));

    ll res = 0;
    for(auto [w, u, v] : vec){
        res += (ll)uf.size(u) * (ll)uf.size(v) * w;
        uf.merge(u, v);
    }
    cout << res << ln;
}
