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

//文字列型の整数比較
//s>tなら1, s==tなら0, s<tなら-1を返す
int compare(string &s, string &t){
    if(s.size() > t.size())return 1;
    if(s.size() < t.size())return -1;
    rep(i, s.size()){
        if(s[i]>t[i])return 1;
        if(s[i]<t[i])return -1;
    }
    return 0;
}

int main(){
    string s, l, r; cin >> s >> l >> r;

    if(s.size()>1 and s[0]=='0'){
        cout << "No" << ln;
        return 0;
    }

    if(compare(s, l) >= 0 and compare(s, r) <= 0)cout << "Yes" << ln;
    else cout << "No" << ln;
}
