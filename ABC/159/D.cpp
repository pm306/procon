#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
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
    vector<ll> A(n), cnt(202020);
    rep(i, n){
        cin >> A[i];
        cnt[A[i]]++;
    }

    ll sum = 0;
    fore(c, cnt)sum += c*(c-1)/2;

    vector<ll> ans;
    fore(a, A){
        ll c = cnt[a];
        ll res = sum - c*(c-1)/2 + (c-1)*(c-2)/2;
        ans.push_back(res);
    }
    fore(a, ans)cout << a << ln;
}

