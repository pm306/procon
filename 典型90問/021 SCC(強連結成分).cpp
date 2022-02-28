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
有向グラフが与えられるので、サイクルごとの頂点数を求めよ

SCC(強連結成分)
以下に詳しい
https://hkawabata.github.io/technical-note/note/Algorithm/graph/scc.html
SCC:=有向グラフで、互いに行き来可能な頂点

有向グラフを「上流」「下流」という概念で考える
SCC1 -> SCC2 へのpathが存在する = SCC1はSCC2より上流にある
DAGをイメージするとわかりやすいか

step 1
dfsで「帰りがけ順に」ラベリングを行う
上流SCCには下流SCCの任意の頂点よりも番号が大きい頂点が最低1つ存在する
未探索の頂点は探索済みの任意の頂点の上流にある

step 2
逆グラフを探索する
「上流」「下流」の関係が逆転する
割り振った番号の大きい順、つまり最下流の頂点から探索する
->ある頂点から移動可能な頂点は同じSCCに属するものだけ
*/


int main(){
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N), Gr(N);
    rep(i, M){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        Gr[b].push_back(a);
    }

    //Strongly Connected Component
    //有向グラフにおいて、互いに行き来可能な頂点の集合

    //step 1 calclate postorder-index
    vector<int> postIdx, seen(N);
    auto dfs = [&](auto&& self, int v) -> void{
        seen[v] = true;
        for(auto e:G[v]){
            if(seen[e])continue;
            self(self, e);
        }
        postIdx.push_back(v);
    };
    rep(i, N)if(!seen[i])dfs(dfs, i);

    //step 2 get SCC-size
    reverse(all(postIdx));
    auto dfs_rev = [&](auto&& self, int v) -> ll{
        seen[v] = true;
        ll res = 1;
        for(auto e:Gr[v]){
            if(seen[e])continue;
            res += self(self, e);
        }
        return res;
    };
    fill(all(seen), 0);
    ll res = 0;
    for(auto i:postIdx){
        if(!seen[i]){
            ll siz = dfs_rev(dfs_rev, i);
            res += siz * (siz - 1) / 2;
        }
    }
    cout << res << ln;
}
