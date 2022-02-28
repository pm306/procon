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
    int n, k; cin >> n >> k;
    int r, s, p; cin >> r >> s >> p;
    string t; cin >> t;

    string his = "";
    rep(i, k){
        if(t[i] == 'r')his += "p";
        if(t[i] == 'p')his += "s";
        if(t[i] == 's')his += "r";
    }
    rept(i, k, n){
        char hand;
        if(t[i] == 'r')hand = 'p';
        if(t[i] == 'p')hand = 's';
        if(t[i] == 's')hand = 'r';
        if(hand == his[i-k])hand = '?';
        his += hand;
    }

    int res = 0;
    rep(i, n){
        if(t[i] == 'r' and his[i] == 'p')res += p;
        if(t[i] == 'p' and his[i] == 's')res += s;
        if(t[i] == 's' and his[i] == 'r')res += r;
    }
    cout << res << ln;
}
