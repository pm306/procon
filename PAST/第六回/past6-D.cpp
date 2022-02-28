#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
和の高速計算
*/

int main(){
    int N, K; cin >> N >> K;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }

    ll sum = accumulate(A.begin(), A.begin()+K, 0LL);
    vector<ll> ans(N-K+1);
    rep(i, N-K+1){
        ans[i] = sum;
        sum -= A[i];
        if(i+K<N)sum += A[i+K];
    }
    for(auto a: ans)cout << a << ln;
}
