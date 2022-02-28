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


int main(){
    int n; cin >> n;
    vector<int> L(n); rep(i, n)cin >> L[i];

    sort(all(L));

    ll res = 0;
    rep(i, n)rept(j, i+1, n){
        int a = L[i], b = L[j];
        int r = lower_bound(all(L), a+b) - L.begin();
        int l = upper_bound(all(L), abs(a-b)) - L.begin();
        ll cnt = r - l;
        if(abs(a-b) < a)cnt--;
        if(abs(a-b) < b)cnt--;
        res += cnt;
    }
    cout << res / 3 << ln;
}
