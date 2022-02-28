#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
////////////////////////////////////////////////////////////////////////////////////////////////////////

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,-1,1};

int main(){
    int h, w; cin >> h >> w;
    vector<string> g(h); rep(i, h)cin >> g[i];

    int res = -1;
    rep(i, h)rep(j, w)if(g[i][j]=='.'){
        vector dist(h, vector<int>(20, 1<<30)); dist[i][j] = 0;
        queue<pair<int, int>> que; que.emplace(i, j);
        while(que.size()){
            auto [y, x] = que.front(); que.pop();
            rep(k, 4){
                int ny = y+dy[k], nx = x+dx[k];
                if(ny<0 or ny>=h or nx<0 or nx>=w or g[ny][nx]=='#')continue;
                if(dist[ny][nx] == 1<<30){
                    dist[ny][nx] = dist[y][x] + 1;
                    chmax(res, dist[ny][nx]);
                    que.emplace(ny, nx);
                }
            }
        }
    }
    cout << res << ln;
}
