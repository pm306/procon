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

using mint = modint1000000007;

int main(){
    int n, k; cin >> n >> k;

    mint res = 0, ma = 0, mi = 0;
    int asc = 0, desc = n;
    for(int i=0; i<k; i++){
        mi += asc++;
        ma += desc--;
    }

    for(int i=k; i<=n+1; i++){
        res += ma - mi + 1;
        mi += asc++;
        ma += desc--;
    }
    cout << res.val() << ln;
}
