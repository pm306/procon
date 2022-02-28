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
    int X[110], Y[110]; rep(i, n)cin >> X[i] >> Y[i];

    string res = "No";
    rep(i, n)rept(j, i+1, n)rept(k, j+1, n){
        int dx1 = X[k] - X[i], dy1 = Y[k] - Y[i];
        int dx2 = X[j] - X[i], dy2 = Y[j] - Y[i];
        if(dx1 * dy2 == dx2 * dy1)res = "Yes";
    }
    cout << res << ln;
}
