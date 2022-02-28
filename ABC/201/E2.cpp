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
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
考察が多段階になっており、やや難しめ。
【考察】
・素朴な解法
木上の２点間の距離はLCAを用いればO(1)で求まるため、全体としてO(2)かかり、間に合わない。

・重みに注目する
重みが和ではなくXORである。XORの性質は
:桁上がりのない加算(独立して考えられる)
:二度足すと0
2つ目の性質を用いると、dist(x,y) = dist(root, x) xor dist(root, y)となることがわかる……1⃣
しかし、これでもO(N^2)なので、更に高速化を図る必要がある

・60層に分離して,0or1演算に帰着
XORの1つ目の性質を利用して、グラフを60層に分離する。
すると、各層の重みを疑似的に 0 or 1 の2通りに分離して考えることができるようになる！……2⃣
イメージとしては、各層の重みが(0or1)<<maskなので、一旦>>maskしてから最後に<<maskして復元する感じ
重みが2通りしかない = マッチングが4パターンしかない！！！！！！……3⃣
→マッチングごとに集計して高速計算できる！
この場合はdist(root,x) != dist(root, y)のペアをマッチングさせれば良いことになる。

あとはこの処理を各層にやればOK
※実装の際は、コスト探索は1回やればOK.後で取り出せる。
※重さが1か判断する時、x & 1<<mask はNGです。x>>mask & 1 にしましょう。
*/

using mint = modint1000000007;
using edge = pair<int, ll>; //to, cost

int main(){
    int N; cin >> N;
    vector<vector<edge>> g(N);
    rep(i, N-1){
        int a, b; ll c; cin >> a >> b >> c; a--, b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    auto dfs = [&](auto&& self, int v, int p, vector<ll>& dist) -> void{
        for(auto& [to, cost]:g[v]){
            if(to == p)continue;
            dist[to] = dist[v] ^ cost;
            self(self, to, v, dist);
        }
    };
    vector<ll> dist(N); dist[0] = 0;
    dfs(dfs, 0, -1, dist);

    mint res = 0;
    rep(mask, 60){
        //add
        mint cnt[2];
        fore(d,dist){
            cnt[d>>mask&1]++;
        }
        res += (cnt[0] * cnt[1]) * (1LL<<mask);

    }
    cout << res.val() << ln;
}

