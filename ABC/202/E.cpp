#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
オイラーツアーという概念を知ってますか？　という問題
*/

int main(){
    int N; cin >> N;
    vector<vector<ll>> children(N), in_list(N);
    vector<int> in(N), out(N), depth(N);

    rept(i,1, N){
        int p; cin >> p;
        children[p-1].push_back(i);
    }

    int timer = 0;
    auto dfs = [&](auto&& self, int v) -> void{
        in[v] = timer++;
        in_list[depth[v]].push_back(in[v]);
        for(auto e: children[v]){
            depth[e] = depth[v] + 1;
            self(self, e);
        }
        out[v] = timer++;
    };
    dfs(dfs, 0);

    int Q; cin >> Q;
    vector<int> ans;
    while(Q--){
        int u, d; cin >> u >> d; u--;
        auto& v = in_list[d];
        int res = lower_bound(all(v), out[u]) - lower_bound(all(v), in[u]);
        ans.push_back(res);
    }
    for(auto a:ans)cout << a << ln;
}

