#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
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

double memo[110][110][110];
double dfs(int a, int b, int c){
    if(a==100 or b==100 or c==100){
        return 0;
    }
    if(memo[a][b][c] != -1){
        return memo[a][b][c];
    }

    double res = 0;
    res += (dfs(a+1, b, c) + 1) * ((double)a / (a + b + c));
    res += (dfs(a, b+1, c) + 1) * ((double)b / (a + b + c));
    res += (dfs(a, b, c+1) + 1) * ((double)c / (a + b + c));
    return memo[a][b][c] = res;
}

int main(){
    int a, b, c; cin >> a >> b >> c;
    rep(i, 110)rep(j, 110)rep(k, 110)memo[i][j][k] = -1;

    cout << fixed << setprecision(12);
    cout << dfs(a, b, c) << ln;
}
