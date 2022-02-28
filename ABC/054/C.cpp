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
1を始点とした全域木がいくつつくれるか？　という問題
ｎが非常に小さいので経路を全探索できる。
next_permtationで経路を作り、すべて到達した場合カウンタを増やす
findがイテレータを返すのを忘れていた
*/

int n, m;
vector<vector<int>> G;
bool dfs(int v, vector<int> path){
    if(path.empty()){
        return true;
    }
    int nv = path.back();
    if(find(all(G[v]), nv)!=G[v].end()){
        path.pop_back();
        return dfs(nv, path);
    }else{
        return false;
    }
}

int main(){
    cin >> n >> m;
    G.resize(n);
    rep(i, m){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int res = 0;
    vector<int> Array; //sorted
    for(int i=1; i<n; i++)Array.push_back(i);
    do {
        if(dfs(0, Array))res++;
    } while (next_permutation(all(Array)));

    cout << res << ln;
}   