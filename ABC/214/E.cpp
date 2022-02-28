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
    int t; cin >> t;

    vector<string> ans;
    while(t--){
        int n; cin >> n;
        vector<pll> sec(n); //L, R
        rep(i, n)cin >> sec[i].first >> sec[i].second;

        sort(all(sec));

        bool ok = true;
        multiset<int> st;
        int idx = 0;
        for(int i=1; i<=(int)1e9; i++){
            while(idx < n and sec[idx].first == i){
                st.insert(sec[idx].second);
                idx++;
            }
            if(st.size())st.erase(st.begin());
            if(st.size() and *st.begin() <= i){
                ok = false;
                break;
            }
            if(st.empty()){
                if(idx == n)break;
                i = sec[idx].first - 1;
            }
        }
        ans.push_back(ok ? "Yes" : "No");
    }
    fore(a, ans)cout << a << ln;
}

