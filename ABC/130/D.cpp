#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(){
    int n; ll k; cin >> n >> k;
    vector<ll> A(n); rep(i, n) cin >> A[i];

    ll res = 0, sum = 0, r = 0;
    rep(l, n){
        while(r<n){
            if(sum+A[r]>=k)break;
            sum += A[r++];
        }
        res += n - r;
        if(l==r)sum += A[r++];
        sum -= A[l];
    }
    cout << res << ln;
}
