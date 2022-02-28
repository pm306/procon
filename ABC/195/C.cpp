#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
桁ごとの数っていくつありますか、みたいな問題

n桁の数はpow(10, n) - pow(10, n-1)個ある

カンマごとに数える方法もあるとか
*/


int main(){
    ll N; cin >> N;
    int keta = to_string(N).size();

    ll res = 0;
    for(int i=1; i<=keta; i++){
        if(keta > i){
            res += (pow(10, i) - pow(10, i-1)) * ((i - 1)/3);
        }else{
            res += (N - pow(10, i-1) + 1) *((i - 1)/3);
        }
    }
    cout << res << ln;
}
