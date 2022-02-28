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
    int N; cin >> N;
    vector<ll> A(N),S(N+1);
    rep(i, N){
        cin >> A[i];
    }

    sort(all(A));
    rep(i, N)S[i+1] = S[i] + A[i];
    ll res = 0;
    rep(i, N-1){
        res += (S[N] - S[i+1]) - (N-1-i) * A[i];
    }
    cout << res << ln;
}
