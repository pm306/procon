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


int main(){
    int N; cin >> N; N *= 2;
    vector<ll> A(N); rep(i, N)cin >> A[i];

    //dp[l][r]:=区間[l,r]を取り除いた時のコスト
    ll dp[440][440];
    //init
    rep(i, N){
        rept(j, i, N){
            dp[i][j] = INF;
        }
        if(i<N-1)dp[i][i+1] = abs(A[i] - A[i+1]);
    }

    auto debug = [&]()->void{
        rep(i, N){
            rep(j, N){
                if(dp[i][j]==INF)cout << "x ";
                else cout << dp[i][j] << " ";
            }cout << ln;
        }
    };
    //debug();

    //dp
    for(int i=3; i<N; i+=2){
        for(int j=0; j+i<N; j++){
            int cl = j, cr = j+i;
            for(int k=cl; k<cr; k++){
                chmin(dp[cl][cr], dp[cl][k] + dp[k+1][cr]);
            }
            chmin(dp[cl][cr], dp[cl+1][cr-1] + abs(A[cl]-A[cr]));
            //debug();
        }
    }
    cout << dp[0][N-1] << ln;
}
