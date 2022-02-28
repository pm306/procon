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
    int n; cin >> n;
    vector<int> A(n+1); rep(i, n)cin >> A[i+1];

    vector<int> ans(n+1);
    for(int i=n; i>0; i--){
        int cnt = 0;
        for(int j=i; j<=n; j+=i){
            cnt += ans[j];
        }
        if(cnt%2 != A[i])ans[i] = 1;
    }

    cout << accumulate(all(ans), 0) << ln;
    rep(i, ans.size())if(ans[i])cout << i << ln;
}
