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

int main(){
    int n, m; cin >> n >> m;
    vector<ll> A(n); rep(i, n)cin >> A[i];
    vector<vector<pll>> g(n);
    rep(i, m){
        int a, b; ll c; cin >> a >> b >> c; a--, b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    min_priority_queue<pair<ll, int>> que; que.emplace(0, 0);
    vector<ll> dist(n, INF), value(n, 0); dist[0] = 0; value[0] = A[0];
    while(que.size()){
        auto [cost, v] = que.top(); que.pop();
        if(cost > dist[v])continue;

        for(auto [to, nxc] : g[v]){
            ll to_cost = cost + nxc;
            if(chmin(dist[to], to_cost)){
                value[to] = value[v] + A[to];
                que.emplace(to_cost, to);
            }
            else if(to_cost == dist[to]){
                chmax(value[to], value[v] + A[to]);
            }
        }
    }

    cout << value[n-1] << ln;
}


