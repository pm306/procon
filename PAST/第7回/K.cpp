#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using tup = tuple<ll, ll, int>; //cost, val, to

int main(){
    int n, m; cin >> n >> m;
    vector<ll> A(n); rep(i, n)cin >> A[i];
    vector<vector<pll>> g(n);
    rep(i, m){
        int a, b; ll c; cin >> a >> b >> c; a--, b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    vector<pll> ans; //ゴールまでの総コスト,満足度
    min_priority_queue<tup> que; que.emplace(0, A[0], 0);
    vector<ll> dist(n, INF); dist[0] = 0;
    vector<pll> V(n, {0, INF}); V[0] = {A[0], 0}; //頂点nを訪れた時の最大満足度, 最小コスト候補
    while(que.size()){
        auto [cost, val, v] = que.top(); que.pop();
        //cout << "v:" << v << " sec:" << V[v].second << " cost:" << cost << ln;
        if(V[v].second == cost)chmax(val, V[v].first);
        if(cost > dist[v])continue;

        for(auto [to, nxc]:g[v]){
            if(to == n-1){
                ans.emplace_back(cost+nxc, val+A[to]);
            }
            if(chmin(dist[to], cost + nxc)){
                que.emplace(dist[to], val + A[to], to);
                if(V[to].first < val + A[to]){
                    V[to] = {val + A[to], cost+nxc};
                }
            }
            else if(dist[to] == cost + nxc){
                if(V[to].first < val + A[to]){
                    V[to] = {val + A[to], cost+nxc};//同時に訪れたなら最大満足度を更新
                }
            }
        }
    }
    ll res = -1;
    for(auto [cost, val]:ans)if(cost == dist[n-1])chmax(res, val);
    cout << res << ln;
}
