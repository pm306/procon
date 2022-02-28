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
    vector<vector<int>> g(n);
    rep(i, n-1){
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    rep(i, n)sort(all(g[i]));

    vector<int> seen(n);
    auto dfs = [&](auto dfs, int v) -> void{
        cout << v << " ";
        seen[v] = true;

        fore(e, g[v])if(!seen[e]){
            dfs(dfs, e);
            cout << v << " ";
        }
    };
    dfs(dfs, 0);
}

