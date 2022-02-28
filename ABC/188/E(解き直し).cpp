#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


ll dp[202020]; //街iで金を売る時、持ち込める金の最低価格
int main(){
    int N, M; cin >> N >> M;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }

    vector<vector<int>> G(N);
    rep(i, M){
        int a, b; cin >> a >> b;
        G[--a].push_back(--b);
    }

    fill(dp, dp+N, LINF);
    rep(i, N-1){
        for(auto e:G[i]){
            dp[e] = min({dp[e], dp[i], A[i]});
        }
    }

    ll res = -LINF;
    rept(i, 1, N)chmax(res, A[i] - dp[i]);
    cout << res << ln;
}
