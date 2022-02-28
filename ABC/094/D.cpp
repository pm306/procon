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
    vector<int> A(n); rep(i, n)cin >> A[i];

    sort(all(A));
    if(n == 2){
        cout << A[1] << " " << A[0] << ln;
        return 0;
    }

    auto it = lower_bound(all(A), A[n-1]/2);
    if(it == A.begin()){
        cout << A[n-1] << " " << *it << ln;
    }
    else{
        int ans1 = *it;
        int ans2 = *(--it);
        if(abs(A[n-1]/2 - ans1) <= abs(A[n-1]/2 - ans2)){
            cout << A[n-1] << " " << ans1 << ln;
        }
        else{
            cout << A[n-1] << " " << ans2 << ln;
        }
    }
}
