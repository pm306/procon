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
    ll N; cin >> N;

    priority_queue<pll> que;
    ll takahashi = 0, aoki = 0;
    rep(i, N){
        ll a, b; cin >> a >> b;
        aoki += a;
        que.push({a*2+b, b});
    }
    int res = 0;
    while(aoki>=takahashi){
        auto p = que.top(); que.pop();
        ll b = p.second, a = (p.first - b) / 2;
        takahashi += a + b;
        aoki -= a;
        res++;
    }
    cout << res << ln;
}
