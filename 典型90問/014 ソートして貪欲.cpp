#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
「交換しても悪化しない」性質を利用した貪欲法。
思いつけなかった。
*/


int main(){
    int N; cin >> N;
    vector<ll> A(N), B(N); rep(i, N)cin >> A[i]; rep(i, N)cin >> B[i];
    sort(all(A)); sort(all(B));
    ll res = 0;
    rep(i, N)res += abs(A[i] - B[i]);
    cout << res << ln;
}
