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
最適戦略問題
葉まで潜ってそこを往復するのが高橋君の最適戦略であることはわかったが、どの葉に潜ればよいかわからず。
実は到達可能な葉すべてを比較すればよかった。
dfs1:vを始点としたときの各頂点への距離
dfs2:uを始点とし、vを根とした木の頂点のうち、ta<daである葉を全部比較する。
*/

int n,u,v;
vector<vector<int>> G;
vector<int> da; 

void dfs1(int v, int p, int d){
    da[v] = d;

    for(auto e:G[v]){
        if(e==p)continue;
        dfs1(e, v, d+1);
    }
}

int res = 0;
void dfs2(int v, int p, int d){
    //エッジ数が１＝葉
    if(G[v].size()==1 and d < da[v]){
        chmax(res, da[v]-1);
    }

    for(auto e: G[v]){
        if(e==p)continue;
        dfs2(e, v, d+1);
    }
}


int main(){
    cin >> n >> u >> v; u--, v--;
    G.resize(n), da.resize(n);
    rep(i, n-1){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs1(v, -1, 0);
    dfs2(u, -1, 0);
    cout << res << ln;
}   