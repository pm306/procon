#include <bits/stdc++.h>
using namespace std;
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
    int N; ll C; cin >> N >> C;
    map<int, ll> imos;
    rep(i, N){
        ll a, b, c; cin >> a >> b >> c;
        imos[a] += c;
        imos[b+1] -= c;
    }

    ll bef = 0, price = 0, res = 0;
    for(auto& [day, cost]:imos){
        //安い方を選ぶ
        res += (day - bef) * min(C, price);
        bef = day, price += cost;
    }
    cout << res << ln;
}
