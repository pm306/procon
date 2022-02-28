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


int main(){
    string s; cin >> s;

    int res = 0;
    rep(i, 10000){
        int C[10]{};
        int x = i;
        rep(j, 4){ //4桁に達してない場合、C[0] = true になる
            C[x%10] = true;
            x /= 10;
        }
        bool ok = true;
        rep(j, 10){
            if(s[j]=='o' and !C[j])ok = false;
            if(s[j]=='x' and C[j])ok = false;
        }
        res += ok;
    }
    cout << res << ln;
}

