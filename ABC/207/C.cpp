#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1<<30;
constexpr long long LINF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int N; cin >> N;
    vector<ll> L(N), R(N);
    rep(i, N){
        ll t; cin >> t >> L[i] >> R[i]; L[i]*=2; R[i]*=2;
        if(t==2 or t==4)R[i]--;
        if(t==3 or t==4)L[i]++;
    }
    ll res = 0;
    rep(i, N){
        rept(j, i+1, N){
            if(!(R[i] < L[j] or R[j] < L[i]))res++;
        }
    }
    cout << res << ln;
}
