#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1<<30;
constexpr long long LINF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int L, R; cin >> L >> R;

    vector<ll> C(1010101);//C[g]:=(i,j)(L<=i,j<=R)のうちgcd=gである場合の数
    for(int g=R; g>1; g--){
        C[g] = pow(R/g - (L-1)/g, 2);
        int gg = g*2;
        while(gg<=R){//約数包除
            C[g] -= C[gg];
            gg += g;
        }
    }

    ll res = accumulate(all(C), 0LL);
    //x=g or y=g ※x=yを重複して数えるため-1
    for(int i=max(2,L); i<=R; i++)res -= (R/i - (L-1)/i)* 2 - 1;
    cout << res << ln;
}

