#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
全探索の典型。3重ループ→2重ループ
x,yを定めると条件を満たすzは1or0通りしかないので、zを全探索する必要はない。
*/

int main(){
    int K, S; cin >> K >> S;

    int res = 0;
    rep(x, K+1){
        rep(y, K+1){
            int z = S - (x + y);
            if(z >= 0 and z <= K)res++;
        }
    }
    cout << res << ln;
}
