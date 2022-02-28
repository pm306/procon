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
    int H, W; cin >> H >> W;
    vector A(H, vector<int>(W));
    rep(i, H)rep(j, W)cin >> A[i][j];

    vector<int> yoko(H), tate(W);
    rep(i, H)yoko[i] = accumulate(all(A[i]), 0);
    rep(j, W){
        rep(i, H){
            tate[j] += A[i][j];
        }
    }

    rep(i, H){
        rep(j, W){
            cout << yoko[i] + tate[j] - A[i][j] << " ";
        }cout << ln;
    }
}
