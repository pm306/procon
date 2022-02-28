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
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int N; cin >> N;
    vector<int> C(N+1); rept(i,1, N+1)cin >> C[i];

    int min_even = 1<<30, min_odd = 1<<30;
    rept(i,1, N+1)if(i%2==0)chmin(min_even, C[i]); else chmin(min_odd, C[i]);

    ll res = 0, sale_even = 0, sale_odd = 0;
    int Q; cin >> Q;
    while(Q--){
        int t; cin >> t;
        if(t==1){
            int x, a ;cin >> x >> a;
            if((x%2==0 ? C[x] - sale_even : C[x] - sale_odd) >= a){
                C[x] -= a;
                res += a;
                if(x%2==0)chmin(min_even, C[x]);
                else chmin(min_odd, C[x]);
            }
        }
        else if(t==2){
            ll a; cin >> a;
            if(min_odd >= a){
                res += a * ((N + 1) / 2);
                sale_odd += a;
                min_odd -= a;
            }
        }
        else{
            ll a; cin >> a;
            if(min_odd >= a and min_even >= a){
                res += a * N;
                min_odd -= a;
                min_even -= a;
                sale_even += a;
                sale_odd += a;
            }
        }
    }
    cout << res << ln;
}
