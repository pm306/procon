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
値をまとめて計算する
*/


int main(){
    int N; cin >> N;
    vector<ll> C(500);
    rep(i, N){
        int a; cin >> a; a+=200;
        C[a]++;
    }

    ll res = 0;
    rep(i, 500){
        rept(j, i+1, 500){
            res += (C[i] * C[j]) * pow(i-j, 2);
        }
    }
    cout << res << ln;
}
