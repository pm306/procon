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


ll A[110][110], B[110][110];
int main(){
    int H, W; cin >> H >> W;
    rep(i, H)rep(j, W)cin >> A[i][j];
    rep(i, H)rep(j, W)cin >> B[i][j];

    ll res = 0;
    rep(i, H-1){
        rep(j, W-1){
            ll sa = B[i][j] - A[i][j];
            res += abs(sa);
            A[i][j] += sa;
            A[i+1][j] += sa;
            A[i][j+1] += sa;
            A[i+1][j+1] += sa;
        }
    }
    rep(i, H){
        rep(j, W){
           if(A[i][j] != B[i][j]){
               cout << "No" << ln;
               return 0;
           }
        }
    }
    cout << "Yes" << ln;
    cout << res << ln;
}
