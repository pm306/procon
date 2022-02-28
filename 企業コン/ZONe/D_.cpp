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
    string s; cin >> s;

    string t, tt; bool rev = false;
    fore(c, s){
        if(c == 'R')rev = !rev;
        else if(!rev){
            t += c;
        }
        else{
            tt += c;
        }
    }

    string res;
    if(!rev){
        reverse(all(tt));
        res = tt + t;
    }
    else{
        reverse(all(t));
        res = t + tt;
    }
    string stack;
    fore(c, res){
        if(stack.size() and stack.back() == c)stack.pop_back();
        else stack.push_back(c);
    }
    cout << stack << ln;
}
