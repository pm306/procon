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
いいからシミュレートだ！
紙に書くとわかりやすいよ
*/

int main(){
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    ll res = INF;
    for(int bit=0; bit<1<<N-1; bit++){ //bitが立っている=区間を区切る
        ll val = 0, tmp = 0;
        rep(i, N){
            tmp |= A[i];
            if(i == N-1 or bit>>i&1){
                val ^= tmp;
                tmp = 0;
            }
        }
        chmin(res, val);
    }
    cout << res << ln;
}

