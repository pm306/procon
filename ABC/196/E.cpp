#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
関数合成？
関数の形がどうなるかイメージしていくといいらしい
正直雰囲気で解いてる
*/

int main(){
    int N; cin >> N;
    vector<ll> A(N), T(N);
    rep(i, N)cin >> A[i] >> T[i];
    int Q; cin >> Q;
    vector<ll> X(Q);rep(i, Q)cin >> X[i];

    ll low = -LINF, high = LINF, add = 0;
    rep(i, N){
        if(T[i] == 1){
            low += A[i];
            high += A[i];
            add += A[i];
        }
        if(T[i] == 2){
            chmax(low, A[i]);
            chmax(high, A[i]);
        }
        if(T[i] == 3){
            chmin(low, A[i]); 
            chmin(high, A[i]);
        }
    }
    rep(i, Q)cout << min(max(X[i]+add, low), high) << ln;
}
