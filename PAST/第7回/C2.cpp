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
    string s; cin >> s;
    int l, r; cin >> l >> r;

    if(s.size()>1 and s[0]=='0'){
        cout << "No" << ln;
        return 0;
    }

    if(s.size()>10){
        cout << "No" << ln;
        return 0;
    }

    ll n = stol(s);
    if(l <= n and n <= r)cout << "Yes" << ln;
    else cout << "No" << ln;
}
