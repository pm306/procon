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

ll func(ll n){
    if(n<0)return 0;
    if(n&1){
        if(n%4==3)return 0;
        else return 1;
    }
    else if(n%4==0)return n;
    return n+1;
}

int main(){
    ll A, B; cin >> A >> B;

    //f(A, B) = f(0, B) ^ f(0, A-1)
    cout << (func(B) ^ func(A-1)) << ln;
}

