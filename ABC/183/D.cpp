#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    int N, W; cin >> N >> W;
    vector<ll> imos(202020);
    rep(i, N){
        ll s, t, p; cin >> s >> t >> p;
        imos[s] += p;
        imos[t] -= p;
    }

    string res = "Yes";
    ll water = 0;
    rep(i, 202020){
        water += imos[i];
        if(water>W)res = "No";
    }
    cout << res << ln;
}
