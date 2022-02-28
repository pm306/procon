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

/*
主客転倒　＆　約数系包除
https://blog.hamayanhamayan.com/entry/2020/04/12/225411
*/

using mint = atcoder::modint1000000007;

int main(){
    int N, K;
    cin >> N >> K;

    vector<mint> cnt(K+1);
    for(int g=K; g>0; g--){
        mint tmp = K / g;
        cnt[g] = tmp.pow(N);

        int gg = g * 2;
        while(gg<=K){
            cnt[g] -= cnt[gg];
            gg += g;
        }
    }

    mint res = 0;
    rep(i, cnt.size())res += cnt[i] * i;
    cout << res.val() << ln;
}
