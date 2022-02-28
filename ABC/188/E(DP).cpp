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

int main(){
    int n, m; cin >> n >> m;
    vector<ll> A(n); rep(i, n) cin >> A[i];
    vector<vector<int>> G(n);
    rep(i, m){
        int x,y;cin >> x >> y; x--, y--;
        G[x].push_back(y);
    }

    //動的計画法。
    vector<ll> dp(n, LINF);
    rep(i, n){
        for(auto e: G[i]){
            dp[e] = min({dp[e], dp[i], A[i]});
        }
    }
    ll res = -LINF;
    rep(i, n){
        chmax(res, A[i] - dp[i]);
    }
    cout << res << ln;
}   