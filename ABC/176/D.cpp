#include <bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using plp = pair<ll, pll>; //cost, y, x;

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,-1,1};

int main(){
    int H, W; cin >> H >> W;
    int cy, cx, gy, gx; cin >> cy >> cx >> gy >> gx; cy--, cx--, gy--, gx--;
    vector<string> g(H); rep(i, H)cin >> g[i];

    vector<vector<ll>> dist(H, vector<ll>(W, LINF));
    dist[cy][cx] = 0;
    min_priority_queue<plp> que; que.push({0, {cy, cx}});
    while(que.size()){
        auto p = que.top(); que.pop();
        ll cost = p.first, y = p.second.first, x = p.second.second;
        if(dist[y][x] < cost)continue;
        //徒歩
        rep(k, 4){
            int ny = y+dy[k], nx=x+dx[k];
            if(ny<0 or nx<0 or ny>=H or nx>=W or g[ny][nx]=='#')continue;
            if(dist[ny][nx] > cost){
                dist[ny][nx] = cost;
                que.push({cost, {ny, nx}});
            }
        }
        //ワープ
        for(int ny=y-2; ny<=y+2; ny++){
            for(int nx=x-2; nx<=x+2; nx++){
                if(ny<0 or nx<0 or ny>=H or nx>=W or g[ny][nx]=='#')continue;
                if(dist[ny][nx] > cost + 1){
                    dist[ny][nx] = cost + 1;
                    que.push({cost + 1, {ny, nx}});
                }
            }
        }
    }
    if(dist[gy][gx]==LINF)cout << -1 << ln;
    else cout << dist[gy][gx] << ln;
}
