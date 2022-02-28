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
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};

int H, W;
string g[20];
bool used[20][20];

//バックトラック

int dfs(int sy, int sx, int y, int x){
    if(sx == x and sy == y and used[y][x] == true)return 0; //一筆書き完了
    used[y][x] = true;

    int ret = -10000;
    rep(k, 4){
        int nx = x + dx[k], ny = y + dy[k];
        if(nx<0 or ny<0 or ny>=H or nx>=W or g[ny][nx] == '#')continue;
        if((sx != nx or sy != ny) and used[ny][nx] == true)continue; //行き戻り
        int v = dfs(sy, sx, ny, nx);
        chmax(ret, v+1);
    }
    used[y][x] = false;
    return ret;
}

int main(){
    cin >> H >> W;
    rep(i, H)cin >> g[i];

    int res = -1;
    rep(i, H)rep(j, W)chmax(res, dfs(i,j,i,j));
    if(res <= 2)res = -1;
    cout << res << ln;
}
