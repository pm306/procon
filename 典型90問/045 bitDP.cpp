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


int main(){
    int N, K; cin >> N >> K;
    vector<int> X(N), Y(N);
    for(int i=0; i<N; i++)cin >> X[i] >> Y[i];

    //二点間の距離
    vector<vector<ll>> d(N, vector<ll>(N));
    rep(i, N){
      rep(j, N){
        d[i][j] = (ll)(X[i]-X[j])*(X[i]-X[j]) + (ll)(Y[i]-Y[j])*(Y[i]-Y[j]);
      }
    }

    vector<ll> cost(1 << N); //頂点集合ごとの最大コスト
    for(int bit=1; bit<1<<N; bit++){
        for(int j=0; j<N; j++){
            for(int k=0; k<j; k++){
                if(((bit>>j)&1) == 1 and ((bit >> k)&1) == 1){ //j番目の頂点とk番目の頂点が両方存在する
                    chmax(cost[bit], d[j][k]);
                }
            }
        }
    }

    //dp[cnt][bit]:=既に選んだ点の集合がbitで、現在のグループ数がcntの時のスコア最小値
    vector<vector<ll>> dp(K+1, vector<ll>(1<<N, LINF));
    dp[0][0] = 0;
    for(int i=1; i<=K; i++){ //グループ数
        for(int j=1; j<1<<N; j++){ //頂点集合
            for(int k=j; k!=0; k=(k-1)&j){ //？
                chmin(dp[i][j], max(dp[i-1][j-k], cost[k]));
            }
        }
    }
    cout << dp[K][(1<<N)-1] << ln;
}
