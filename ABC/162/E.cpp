#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
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

using mint = atcoder::modint1000000007;

int main(){
    int N, K;
    cin >> N >> K;

    //sum(gcd=1) + sum(gcd=2) + ... + sum(gcd=K)
    mint res = 0;
    vector<mint> cnt(K+1); //memo[i] = cnt(gcd=i)
    for(int i=K; i>0; i--){
        mint baisu = K / i;
        mint tmp = baisu.pow(N);
        for(int j=i*2; j<=K; j+=i){
            tmp -= cnt[j];
        }
        res += tmp * i; //個数 * gcd
        cnt[i] = tmp;
    }
    cout << res.val() << ln;
}
