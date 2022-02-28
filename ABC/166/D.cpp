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

template<class T> T power(T num, ll a){
     T ret = 1;
        while(a>0){
        if(a&1)ret = ret * num;
        num = num * num;
        a /= 2;
    }
    return ret;
}

int main(){
    ll X; cin >> X;
    for(ll a = -1000; a<=1000; a++){
        for(ll b = -1000; b<=1000; b++){
            if(power(a, 5) - power(b, 5) == X){
                cout << a << " " << b << ln;
                return 0;
            }
        }
    }
}

