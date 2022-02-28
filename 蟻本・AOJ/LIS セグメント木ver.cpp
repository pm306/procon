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

ll op(ll a, ll b){return max(a, b);}
ll e(){return 0;}

int main(){
    vector<int> a{4,2,3,1,5};
    int n = a.size();

    //dp[k]:=値kを増加列の最後に置いたときの、最長増加部分列の長さ
    //遷移 dp[k] = max(dp[0] ~ dp[k-1]) + 1
    segtree<ll, op, e> seg(n+1);
    for(int i=0; i<n; i++){
        seg.set(a[i], seg.prod(0, a[i])+1);
    }
    cout << seg.prod(0, n+1) << ln;
}
