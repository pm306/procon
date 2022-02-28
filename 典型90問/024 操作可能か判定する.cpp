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

/*
偶奇性に着目する
*/

int main(){
    int N, K; cin >> N >> K;
    ll A[1010], B[1010];
    rep(i, N)cin >> A[i];
    rep(i, N)cin >> B[i];

    ll cnt = K;
    rep(i, N)cnt -= abs(A[i] - B[i]);
    if(cnt >= 0 and cnt%2==0)cout << "Yes" << ln;
    else cout << "No" << ln;
}
