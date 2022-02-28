#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using tup = tuple<ll, ll, ll>;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
    int N, M; cin >> N >> M;
    vector<vector<tup>> G(N);
    rep(i, M){
        ll a, b, c, d; cin >> a >> b >> c >> d; a--,b--;
        G[a].emplace_back(b,c,d);
        G[b].emplace_back(a,c,d);
    }

    min_priority_queue<pll> que; //cost, v
    vector<ll> dist(N, LINF); dist[0] = 0;
    que.push({0, 0});
    while(!que.empty()){
        ll cost = que.top().first, v = que.top().second;
        que.pop();
        if(cost > dist[v])continue;
        for(auto& [to, c, d]:G[v]){
            //√d-1に出発するのが最善
            ll tmp = LINF; //到着時間
            //出発する時間
            for(ll t = max(0,(int)sqrt(d)-5); t<(int)sqrt(d)+5; t++){
                if(t < cost)continue;
                chmin(tmp, t + c + d / (t+1));
            }
            //tmp=LINF, すぐ出発するべき場合
            chmin(tmp, cost + c + d / (cost + 1));
            if(dist[to] > tmp){
                dist[to] = tmp;
                que.push({dist[to], to});
            }
        }
    }
    if(dist[N-1]==LINF)cout << -1 << ln;
    else cout << dist[N-1] << ln;
}
