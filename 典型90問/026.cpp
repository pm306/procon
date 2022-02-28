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
2部グラフ＝2色で彩色可能、という性質を知るための問題
*/

int main(){
    int N; cin >> N;
    vector<vector<int>> G(N);
    rep(i, N-1){
        int a, b; cin >> a >> b;
        G[--a].push_back(--b);
        G[b].push_back(a);
    }

    vector<int> odd, even;
    auto dfs = [&](auto&& self, int v, int p, int depth) -> void{
        if(depth%2==0)even.push_back(v);
        else odd.push_back(v);

        for(auto e:G[v]){
            if(e==p)continue;
            self(self, e, v, depth+1);
        }
    };
    dfs(dfs, 0, -1, 0);
    if(odd.size() > even.size()){
        rep(i, N/2)cout << odd[i]+1 << " ";
        cout << ln;
    }
    else{
        rep(i, N/2)cout << even[i]+1 << " ";
        cout << ln;
    }
}
