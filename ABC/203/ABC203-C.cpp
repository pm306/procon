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



int main(){
    ll N, K; cin >> N >> K;
    vector<pll> A(N);
    rep(i, N){
        ll a, b; cin >> a >> b;
        A[i] = {a, b};
    }
    sort(all(A));

    ll pos = 0;
    rep(i, N){
        ll npos = A[i].first, coin = A[i].second;
        if(pos + K < npos){
            cout << pos + K << ln;
            return 0;
        }
        K -= npos - pos;
        pos = npos;
        K += coin;
    }
    cout << pos + K << ln;
}
