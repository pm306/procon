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


double memo[110][110][110];
double dp(int a, int b, int c){
    if(a==100 or b==100 or c==100)return 0.0;

    if(memo[a][b][c] >= 0)return memo[a][b][c];

    double ret = 0.0;
    ret += (dp(a+1, b, c) + 1) * ((double)a / (a + b + c));
    ret += (dp(a, b+1, c) + 1) * ((double)b / (a + b + c));
    ret += (dp(a, b, c+1) + 1) * ((double)c / (a + b + c));

    return memo[a][b][c] = ret;
}

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    memset(memo, -1, sizeof(memo));

    cout << fixed << setprecision(12);
    cout << dp(A, B, C) << ln;
}

