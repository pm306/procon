#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    int N; cin >> N;
    ll mod46[3][50]{};
    rep(i, 3){
        rep(j, N){
            int a; cin >> a; a %= 46;
            mod46[i][a]++;
        }
    }
    ll res = 0;
    rep(i, 46){
        rep(j, 46){
            rep(k, 46){
                if((i+j+k)%46 != 0)continue;
                res += mod46[0][i] * mod46[1][j] * mod46[2][k];
            }
        }
    }
    cout << res << ln;
}
