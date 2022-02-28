#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
全探索しようとすると一見間に合わない。
が、「条件を満たす」パターンを全探索するなら実は間に合う。

塗り方は連結成分ごとに独立なので、連結成分の座標をdfsなりufなりで求める。
その後、連結成分ごとに、頂点を前から全パターン塗って、隣接点が同じ色で塗られたら即やめる。
*/

int main(){
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, M){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> seen(N);
    //連結成分の頂点集合を配列で取得する
    auto dfs = [&](auto&& self, int v, vector<int>& S) -> void{
        seen[v] = true;
        S.push_back(v);
        for(auto e: G[v]){
            if(!seen[e]){
                self(self, e, S);
            }
        }
    };

    //頂点集合ごとに始点の色を決めて彩色する
    //集合を前から再帰的に彩色して、隣接頂点が同色だったら即切る。
    //最後まで彩色できたらその彩色パターンはOKなので1を返す
    //p:頂点のポインタ Cは高々20以下なのでコピーOK

    //隣接色チェック→末尾チェック→次頂点を3通りで塗って進む
    auto paint = [&](auto&& self, int p, vector<int> C, vector<int>& S) -> ll{
        int v = S[p];
        for(auto e: G[v]){
            if(C[e] == C[v]){ //隣接頂点が同色で塗られていれば彩色失敗
                return 0;
            }
        }
        if(p==S.size() - 1){
            return 1; //彩色成功
        }
        ll res = 0;
        rep(i, 3){
            C[S[p+1]] = i; //次の頂点を彩色(全探索)
            res += self(self, p+1, C, S);
        }
        return res;
    };

    ll res = 1;

    rep(i, N){
        if(seen[i])continue;
        vector<int> S;//連結成分の頂点の集合
        dfs(dfs, i, S);
        vector<int> C(N, -1); C[i] = 0; //色(0~2)
        res *= paint(paint, 0, C, S) * 3;
    }
    cout << res << ln;
}
