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


int dp[110][101010], A[110], B[110];
int main(){
    int N, S; cin >> N >> S;
    rep(i, N)cin >> A[i] >> B[i];

    dp[0][0] = true;
    rep(i, N){
        rep(j, S+1){
            if(!dp[i][j])continue;
            if(j+A[i]<=S)dp[i+1][j+A[i]] = true;
            if(j+B[i]<=S)dp[i+1][j+B[i]] = true;
        }
    }

    if(!dp[N][S])cout << "Impossible" << ln;
    else{
        string res = "";
        int pos = S;
        for(int i=N-1; i>=0; i--){
            int p1 = pos - A[i];
            if(p1>=0 and dp[i][p1]){
                pos = p1;
                res += "A";
                continue;
            }
            int p2 = pos - B[i];
            pos = p2;
            res += "B";
        }
        reverse(all(res));
        cout << res << ln;
    }
}
