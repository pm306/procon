#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
習得度：◎
・最小値の最大化→xを二分探索して、最小値をx以上にできるかどうか
*/


int main(){
    ll N, L, K; cin >> N >> L >> K;
    vector<ll> A(N); rep(i, N)cin >> A[i];

    auto check = [&](ll val) -> bool{
        ll cnt = 0, pre = 0;
        rep(i, N){
            if(A[i]-pre >= val and L - A[i] >= val){
                cnt++;
                pre = A[i];
            }
        }
        return cnt >= K;
    };

    ll lo = -1, hi = L+1;
    while(hi-lo>1){
        ll mid = (lo+hi) / 2;
        if(check(mid))lo = mid;
        else hi = mid;
    }
    cout << lo << ln;
}
