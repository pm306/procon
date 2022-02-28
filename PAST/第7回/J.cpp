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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
    }

    string res = "No";
    vector<int> seen(n), state(n);
    auto dfs = [&](auto dfs, int v) -> bool{
        seen[v] = state[v] = true;
        for(auto to:g[v]){
            if(state[to])return false;
            if(seen[to])continue;
            if(dfs(dfs, to) == false)return false;
        }
        state[v] = false;
        return true;
    };

    rep(i, n){
        if(seen[i])continue;
        bool ret = dfs(dfs, i);
        if(ret == false)res = "Yes";
    }
    cout << res << ln;
}
