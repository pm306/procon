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
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    int N, P, Q; cin >> N >> P >> Q;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    ll res = 0;
    rep(a, N){
        rept(b, a+1, N){
            rept(c, b+1, N){
                rept(d, c+1, N){
                    rept(e, d+1, N){
                        if(A[a]%P * A[b]%P * A[c]%P * A[d]%P * A[e]%P == Q)res++;
                    }
                }
            }
        }
    }
    cout << res << ln;
}

