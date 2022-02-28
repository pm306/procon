#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int N, P, K; cin >> N >> P >> K;
    ll A[44][44];
    rep(i, N)rep(j, N)cin >> A[i][j];

    auto check = [&](ll x) -> int{
        vector dp(N, vector<ll>(N, INF));
        rep(i, N)rep(j, N)dp[i][j] = (A[i][j] == -1 ? x : A[i][j]);

        rep(k, N)rep(i, N)rep(j, N){
            chmin(dp[i][j], dp[i][k] + dp[k][j]);
        }

        int cnt = 0;
        rep(i, N)rept(j, i+1, N)if(dp[i][j]<=P)cnt++;
        return cnt;
    };

    ll lo = 0, hi = INF, l, r;
    while(hi-lo>1){
        ll mid = (hi+lo)/2;
        if(check(mid) >= K)lo = mid;
        else hi = mid;
    }
    r = lo;
    if(r == INF - 1 and check(INF) == K){
        cout << "Infinity" << ln;
        return 0;
    }

    lo = 0, hi = INF;
    while(hi-lo>1){
        ll mid = (hi+lo)/2;
        if(check(mid) <= K)hi = mid;
        else lo = mid;
    }
    l = lo;
    cout << r - l << ln;
}
