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

/*
解説に準拠した実装
1次元*4回に帰着して前処理をする
前のコードは何やってるのかわからん。こっちのがわかりやすくて良い
*/

int L[2020][2020], R[2020][2020], U[2020][2020], D[2020][2020];
int main(){
    int H, W; cin >> H >> W;
    vector<string> g(H); rep(i, H)cin >> g[i];

    rep(i, H){
        rep(j, W){
            if(g[i][j] == '#')L[i][j] = U[i][j] = 0;
            else{
                if(j==0)L[i][j] = 1;
                else L[i][j] = L[i][j-1] + 1;
                if(i==0)U[i][j] = 1;
                else U[i][j] = U[i-1][j] + 1;
            }
        }
    }
    rrep(i, H-1){
        rrep(j, W-1){
            if(g[i][j] == '#')R[i][j] = D[i][j] = 0;
            else{
                if(j==W-1)R[i][j] = 1;
                else R[i][j] = R[i][j+1] + 1;
                if(i==H-1)D[i][j] = 1;
                else D[i][j] = D[i+1][j] + 1;
            }
        }
    }
    int res = 0;
    rep(i, H){
        rep(j, W){
            chmax(res, L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3);
        }
    }
    cout << res << ln;
}
