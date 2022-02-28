#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
自己流解法
約1時間
dfs
各ノードごとに、そのノードを根とした部分木を考えて「最深値と2番目に深い値の合計+1」を求め、最も良い値を答えとする
未証明。
*/

using graph = vector<vector<int>>;

int main(){
    int N; cin >> N;
    graph G(N);
    rep(i, N-1){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int res = 0;
    auto dfs = [&](auto&& self, int v, int p) -> int{
        vector<int> dist{0, 0}; //vを根とした部分木のうち、葉との距離
        for(auto e: G[v]){
            if(e == p)continue;
            int ret = self(self, e, v) + 1;
            dist.push_back(ret);
        }
        sort(all(dist), greater<int>());
        int mx = dist[0] + dist[1] + 1;
        chmax(res, mx);
        return dist[0];
    };
    dfs(dfs, 0, -1);
    cout << res << ln;

}

