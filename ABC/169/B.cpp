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
オーバーフロー検知に128ビット整数型を使うと楽　という実装
*/

int main(){
    int N; cin >> N;
    ll A[101010];
    rep(i, N){
        cin >> A[i];
        if(A[i]==0){
            cout << 0 << ln;
            return 0;
        }
    }

    __int128 tmp = 1;
    rep(i, N){
        tmp *= A[i];
        if(tmp > (ll)1e18){
            cout << -1 << ln;
            return 0;
        }
    }
    ll res = tmp;
    cout << res << ln;
}

