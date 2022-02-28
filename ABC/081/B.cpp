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
数列をビット列、2で割る操作を右ビットシフトに置き換えて考えている。
すべてのAのビット和を取り、0ビット目が1(=奇数が1つでも含まれる)になるまでビットシフトを繰り返す
*/

int main(){
    int N; cin >> N;

    int b = 0, res = 0; //b:=Aのビット和
    rep(i, N){
        int a; cin >> a;
        b |= a;
    }
    while(!(b&1)){
        b >>= 1;
        res++;
    }
    cout << res << ln;
}

