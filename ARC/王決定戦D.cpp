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

/*
写経
区間取得だがセグ木でも間に合わない。遅延評価だと間に合うらしい
切って0にするのではなく、区間が含まれるTの最大値を取得する、という考えに転換する
後ろから見ていく問題
インデックスをsetに入れて、whileとにぶたんで区間処理してる。すごい。
*/

int main(){
    int n, m; cin >> n >> m;
    vector<int> T(m), L(m), R(m);
    rep(i, m)cin >> T[i] >> L[i] >> R[i], L[i]--;

    set<int> st;
    rep(i, n)st.insert(i);

    ll res = 0;
    for(int i=m-1; i>=0; i--){
        auto it = st.lower_bound(L[i]);

        while(it != st.end() && *it < R[i]){
            res += T[i];
            auto it2 = it;
            it2++;
            st.erase(it);
            it = it2;
        }
    }
    cout << res << ln; 
}   