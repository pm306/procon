#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
関数がないので作った
*/

string str_lower(string s){
    for(auto& a:s)if(a >= 'A' and a <= 'Z')a = (char)(tolower(a));
    return s;
}

int main(){
    string s, t; cin >> s >> t;
    if(s == t)cout << "same" << ln;
    else if(str_lower(s) == str_lower(t))cout << "case-insensitive" << ln;
    else cout << "different" << ln;
}
