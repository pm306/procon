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
    vector<vector<pair<int, int>>> task(100000);
    rep(i, n){
        int d, s, t; cin >> d >> s >> t; d--;
        task[d].emplace_back(s, t);
    }
    rep(i, n)sort(all(task[i]));

    string res = "No";
    rep(i, 100000){
        int pre_end = -1;
        for(auto [s, t]:task[i]){
            if(pre_end > s)res = "Yes";
            pre_end = t;
        }
    }
    cout << res << ln;
}
