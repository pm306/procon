#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using stop = pair<ll, pll>; //x, s, t;

/*
二分探索で区間を求める問題。
vectorで二分探索すると区間処理に時間がかかるので、
setで探索しつつ、探索終了した範囲を消していく。

setに関するテクニックが満載
*/

int main(){
    int n, q; cin >> n >> q;
    vector<stop> stops(n);
    rep(i, n){
        int s, t, x; cin >> s >> t >> x;
        stops[i] = {x, {s,t}};
    }
    sort(all(stops));

    set<pll> st;
    for(int i=0; i<q; i++){
        ll d; cin >> d;
        st.emplace(d,i);
    }

    vector<ll> ans(q, -1);
    for(auto a:stops){
        int x = a.first, s = a.second.first, t = a.second.second;
        auto left = st.lower_bound({s-x,0});
        auto right = st.lower_bound({t-x,0});
        for(auto it = left; it != right; it++){
            ans[it->second] = x;
        }
        st.erase(left, right);
    }
    for(auto a: ans)cout << a << ln;
}   