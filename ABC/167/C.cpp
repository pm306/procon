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
    int n, m, x; cin >> n >> m >> x;
    vector<int> C(n);
    vector A(n, vector<int>(m));
    rep(i, n){
        cin >> C[i];
        rep(j, m)cin >> A[i][j];
    }

    int res = 1<<30;
    for(int bit=0; bit<1<<n; bit++){
        vector<int> score(m); int cost = 0;
        for(int i=0; i<n; i++)if(bit>>i&1){
            cost += C[i];
            rep(j, m)score[j] += A[i][j];
        }
        bool ok = true;
        rep(i, m)if(score[i]<x)ok = false;
        if(ok)chmin(res, cost);
    }

    if(res==1<<30)res = -1;
    cout << res << ln;
}
