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

string base_10_to_n(ll X, int n){
    if(X/n)return base_10_to_n(X/n, n) + to_string(X%n);
    return to_string(X%n);
}

int main(){
    int n; cin >> n;

    int res = 0;
    rept(i, 1, n+1){
        if(to_string(i).find('7') == -1 and base_10_to_n(i, 8).find('7') == -1)res++;
    }
    cout << res << ln;
}
