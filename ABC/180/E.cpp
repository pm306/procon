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

ll shortest_Hamiltonaian_Path(vector<vector<ll>>& adj){
    int k = adj.size();
    ll inf = 1LL<<60;
    //dp[mask][i]:=通過済みの地点の集合がmaskで、現在地が頂点iである場合の最小コスト
    vector<vector<ll>> dp(1 << k, vector<ll>(k, inf));

    //init
    //単一始点
    dp[0][0] = 0;
    //複数始点
    //for(int i=0; i<k; i++)dp[0][i] = 0;

    for(int mask=1; mask<(1<<k)-1; mask++){
        for(int i=0; i<k; i++){
            if(!(mask >> i & 1)){
                for(int j=0; j<k; j++){
                    if(mask >> j & 1){
                        chmin(dp[mask][i], adj[j][i] + dp[mask ^ 1 << j][j]);
                    }
                }
            }
        }
    }
    ll res = inf;
    //最短ハミルトン閉路
    rep(i, k)chmin(res, dp[((1<<k)-1) ^ 1 << i][i] + adj[i][0]);
    //最短ハミルトン路
    //rep(i, k)chmin(res, dp[((1<<k)-1) & 1 << i][i]);
    return res;
}

ll X[20], Y[20], Z[20];
int main(){
    int N; cin >> N;
    rep(i, N)cin >> X[i] >> Y[i] >> Z[i];

    vector<vector<ll>> adj(N, vector<ll>(N));
    rep(i, N){
        rep(j, N){
            adj[i][j] = abs(X[j]-X[i]) + abs(Y[j]-Y[i]) + max(0LL, Z[j]-Z[i]);
        }
    }

    cout << tsp_to_return(adj) << ln;
}

