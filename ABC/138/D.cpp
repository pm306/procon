#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
遅延評価の基本みたいな問題
必要な場所にメモっておいて、最後にまとめて評価する
*/

int main(){
    int N, Q; cin >> N >> Q;
    vector<vector<int>> g(N);
    rep(i, N-1){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> eval(N);
    while(Q--){
        ll p, x; cin >> p >> x; p--;
        eval[p] += x;
    }

    vector<int> ans(N);
    auto dfs = [&](auto&& self, int v, int p, ll val) -> void{
        val += eval[v];
        ans[v] = val;
        fore(nv, g[v]){
            if(nv == p)continue;
            self(self, nv, v, val);
        }
    };
    dfs(dfs, 0, -1, 0);

    fore(a,ans)cout << a << " ";
    cout << ln;
}

