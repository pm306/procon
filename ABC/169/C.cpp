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
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
小数のfloor演算
誤差対策として
１：丸める
２：文字列として受け取る
がある。
積算は整数にして行ってから100で割るべき。
*/

int main(){
    ll a; string s; cin >> a >> s;
    ll b = (s[0]-'0') * 100 + (s[2]-'0') * 10 + (s[3]-'0');
    cout << (a * b) / 100 << ln;
}

