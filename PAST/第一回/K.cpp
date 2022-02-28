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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
オイラーツアー
行きがけの時間と帰りがけの時間を記録して判定に使う
*/

int main(){
    int N; cin >> N;
    vector<vector<ll>> children(N);
    vector<int> in(N), out(N);
    int root;

    rep(i, N){
        int p; cin >> p;
        if(p!=-1)children[p-1].push_back(i);
        else root = i;
    }

    int timer = 0;
    auto dfs = [&](auto&& self, int v) -> void{
        in[v] = timer++;
        for(auto e: children[v]){
            self(self, e);
        }
        out[v] = timer++;
    };
    dfs(dfs, root);

    int Q; cin >> Q;
    vector<string> ans;
    while(Q--){
        int a, b; cin >> a >> b, a--, b--;
        if(in[a] > in[b] and out[a] < out[b])ans.push_back("Yes");
        else ans.push_back("No");
    }
    for(auto& a:ans)cout << a << ln;
}

