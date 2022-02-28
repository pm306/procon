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
    vector<ll> A(n), F(n);
    rep(i, n)cin >> A[i];
    rep(i, n)cin >> F[i];

    sort(all(A));
    sort(all(F), greater<ll>());

    //a*f>xのとき、a*f<=xとなる最大のaを返す
    auto func = [&](ll a, ll f, ll x) -> ll{
        ll lo = -1, hi = a;
        while(hi-lo>1){
            ll mi = (hi+lo)/2;
            if(mi*f>x)hi=mi;
            else lo=mi;
        }
        return lo;
    };

    //k回以内の修行で最大コストをX以下にできるか？
    auto check = [&](ll x) -> bool{
        ll cnt = 0;
        rep(i, n){
            ll a = A[i], f = F[i];
            if(a*f<=x)continue;
            cnt += a - func(a, f, x);
        }
        return cnt <= k;
    };

    ll lo = -1, hi = INF;
    while(hi-lo>1){
        ll mi = (hi+lo)/2;
        if(check(mi))hi=mi;
        else lo=mi;
    }
    cout << hi << ln;
}
