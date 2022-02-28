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
テーブル削減を用いたナップザックDP。
遷移が２つのみかつ右方向への移動のみ
→後ろから更新することで矛盾なく更新ができる。
*/

int main(){
    int N, W; cin >> N >> W;
    ll weight[110],value[110];
    rep(i, N)cin >> weight[i] >> value[i];

    vector<ll> dp(101010, -1);
    dp[0] = 0;
    for(int i=0; i<N; i++){
        for(int j=W; j>=0; j--){
            if(dp[j]==-1)continue;
            if(j+weight[i]<=W)chmax(dp[j+weight[i]], dp[j]+value[i]);
        }
    }
    cout << *max_element(all(dp)) << ln;
}


