#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1<<30;
constexpr long long LINF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
bitDPの典型問題
https://kotamanegi.com/Problems/view/?page=70
*/

ll shortest_Hamiltonaian_Path(vector<vector<ll>>& adj, vector<int>& T, bool is_cycle=false, int s=-1){
    int k = adj.size();
    ll inf = 1LL<<60;
    //dp[mask][i]:=通過済みの地点の集合がmaskで、現在地が頂点iである場合の最小コスト
    vector<vector<ll>> dp(1 << k, vector<ll>(k, inf));

    //init
    //複数始点
    if(s==-1)for(int i=0; i<k; i++)dp[0][i] = T[i];
    //単一始点
    else dp[0][s] = 0;

    for(int mask=1; mask<(1<<k)-1; mask++){
        for(int i=0; i<k; i++){
            if(!(mask >> i & 1)){
                for(int j=0; j<k; j++){
                    if(mask >> j & 1){
                        ll cost = T[i];
                        rep(l, k){
                            if(mask>>l&1)cost -= adj[l][i];
                        }
                        cost = max(0LL, cost);
                        chmin(dp[mask][i], dp[mask ^ 1 << j][j] + cost);
                    }
                }
            }
        }
    }

    ll res = inf;
    rep(i, k)chmin(res, dp[((1<<k)-1) ^ 1 << i][i] + (is_cycle ? adj[i][s] : 0));
    return res;
}

int main(){
    int N; cin >> N;
    vector<int> T(N); rep(i, N)cin >> T[i];
    vector<vector<ll>> adj(N, vector<ll>(N));
    rep(i, N)rep(j, N)cin >> adj[i][j];

    cout << shortest_Hamiltonaian_Path(adj, T) << ln;
}
