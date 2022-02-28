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




int main(){
    int N, K;
    cin >> N >> K;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    vector<int> dp(202020);
    dp[0] = -1;
    for(int i=0; i<K; i++){
        if(dp[i] == 1)continue;
        dp[i] = -1;
        fore(a, A){
            dp[i + a] = 1;
        }
    }
    cout << (dp[K] ? "First" : "Second") << ln;
}

