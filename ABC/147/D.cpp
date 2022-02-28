#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
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
例によってbitごとに考える
A[i]を決めた時、A[j] != A[i]であるA[j]の数(i<j)が、値が0にならないペア
それを累積和で数えてから復元する
*/

using mint = modint1000000007;

int main(){
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    mint res = 0;
    rep(mask, 60){
        vector<mint> S1(N+1), S0(N+1);
        rep(i, N){
            int bit = A[i]>>mask&1;
            S1[i+1] = S1[i] + bit;
            S0[i+1] = S0[i] + !bit;
        }

        mint tmp = 0;
        rep(i, N-1){
            if(A[i]>>mask&1){
                tmp += (S0[N] - S0[i+1]);
            }
            else{
                tmp += (S1[N] - S1[i+1]);
            }
        }
        res += tmp * (1LL<<mask);
    }
    cout << res.val() << ln;
}

