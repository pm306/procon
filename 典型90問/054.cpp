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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
辺数削減→中継点の設定
*/

struct edge{ll to;};
using graph = vector<vector<edge>>;

int main(){
    int N, M; cin >> N >> M;
    graph G(N+M);
    rep(i, M){
        int K; cin >> K;
        rep(j, K){
            int r; cin >> r; r--;
            G[r].push_back({N+i});
            G[N+i].push_back({r});
        }
    }

    //bfs
    queue<int> que; que.push(0);
    vector<int> costs(N+M, INF); costs[0] = 0;
    while(que.size()){
        int v = que.front(); que.pop();
        for(auto& e:G[v]){
            if(costs[e.to]==INF){
                costs[e.to] = costs[v] + 1;
                que.push(e.to);
            }
        }
    }

    rep(i, N){
        cout << (costs[i]==INF ? -1 : costs[i] / 2) << ln;
    }
}

