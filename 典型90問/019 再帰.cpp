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


int N;
ll A[440];
ll dp[440][440]; //dp[i][j]:=区間[i, j)を取り除いたときのコスト

ll rec(int cl, int cr){
    if((cr-cl) == 2){
        return abs(A[cr-1] - A[cl]);
    }
    ll& res = dp[cl][cr];
    if(res != INF)return res;

    chmin(res, rec(cl+1, cr-1) + abs(A[cr-1] - A[cl]));
    for(int k=cl+2; k+1<cr; k+=2){
        chmin(res, rec(cl, k) + rec(k, cr));
    }
    return res;
}
int main(){
    cin >> N; N *= 2;
    rep(i, N)cin >> A[i];

    rep(i, N+1){
        rep(j, N+1){
            dp[i][j] = INF;
        }
    }
    cout << rec(0, N) << ln;
}
