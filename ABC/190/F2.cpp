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
    int n; cin >> n;
    vector<int> A(n); rep(i, n) cin >> A[i];

    fenwick_tree<int> BIT(n);
    vector<ll> ans(n);
    rep(i, n){
        ans[0] += i - BIT.sum(0, A[i]);
        BIT.add(A[i], 1);
    }

    rept(i, 1, n){
        int sub = BIT.sum(0, A[i-1]);
        int add = n - 1 - sub;
        ans[i] = ans[i-1] + add - sub;
    }
    fore(a, ans)cout << a << ln;
}

