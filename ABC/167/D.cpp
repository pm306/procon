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



int main(){
    int n; ll k; cin >> n >> k;
    vector<int> A(n); rep(i, n)cin >> A[i], A[i]--;

    vector table(60, vector<int>(n));
    rep(i, n)table[0][i] = A[i];
    rept(p, 1, 60)rep(i, n){
        table[p][i] = table[p-1][table[p-1][i]];
    }

    int now = 0;
    rrep(p, 60){
        if(k >= 1ll<<p){
            now = table[p][now];
            k -= 1ll<<p;
        }
    }
    cout << now + 1 << ln;
}
