#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
貪欲法。最大数で最小数を塗り替えていく。
ループ抜けがダサい。
*/

int main(){
    int n, m; cin >> n >> m;
    vector<ll> A(n); rep(i, n) cin >> A[i];
    vector<pll> change;
    rep(i, m){
        ll b, c; cin >> b >> c;
        change.emplace_back(c,b);
    }
    sort(all(A));
    sort(all(change), greater<pll>());

    int id = 0, fg = false;
    for(auto u: change){
        ll c = u.first, b = u.second;
        rep(i, b){
            if(c>A[id]){
                A[id] = c;
                id++;
            }else{
                fg = true;
            }
            if(id==n or fg)break;
        }
        if(id==n or fg)break;
    }
    ll res = accumulate(all(A), 0LL);
    cout << res << ln;
}   