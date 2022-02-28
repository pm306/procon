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
    int q; cin >> q;

    vector<ll> ans;
    multiset<ll> st;
    ll add = 0;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll x; cin >> x;
            st.insert(x - add);
        }
        if(t == 2){
            ll x; cin >> x;
            add += x;
        }
        if(t == 3){
            ll x = *st.begin();
            ans.emplace_back(x + add);
            st.erase(st.find(x));
        }
    }
    fore(a, ans)cout << a << ln;
}
