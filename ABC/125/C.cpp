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
    int n; cin >> n;
    vector<int> A(n); rep(i, n)cin >> A[i];

    vector<int> gl(n+1), gr(n+1);
    rep(i, n){
        gl[i+1] = gcd(gl[i], A[i]);
        gr[i+1] = gcd(gr[i], A[n-1-i]);
    }

    int res = -1;
    rep(i, n){
        chmax(res, gcd(gl[i], gr[n-1-i]));
    }
    cout << res << ln;
}
