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
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

using vertex = tuple<int, int, int>; //x,y,z
using plt = pair<ll, vertex>;

ll A[505][505], B[505][505], dist[505][505][2];
int main(){
    int H, W; cin >> H >> W;

    rep(i, H)rep(j, W-1)cin >> A[i][j];
    rep(i, H-1)rep(j, W)cin >> B[i][j];

    //dijkstra
    min_priority_queue<plt> que;
    que.push({0, {0,0,0}});
    rep(i,505)rep(j, 505)rep(k,2)dist[i][j][k] = LINF;
    dist[0][0][0] = 0;

    while(que.size()){
        auto p = que.top(); que.pop();
        int x = get<0>(p.second), y = get<1>(p.second), z = get<2>(p.second);
        ll dv = dist[y][x][z], cost = p.first;
        if(dv < cost)continue;
        //地上
        if(z == 0){
            //left
            if(x and dist[y][x-1][z] > dv + A[y][x-1]){
                dist[y][x-1][z] = dv +A[y][x-1];
                que.push({dv+A[y][x-1], {x-1, y, z}});
            }
            //right
            if(x < W-1 and dist[y][x+1][z] > dv + A[y][x]){
                dist[y][x+1][z] = dv +A[y][x];
                que.push({dv+A[y][x], {x+1, y, z}});
            }
            //down
            if(y < H-1 and dist[y+1][x][z] > dv + B[y][x]){
                dist[y+1][x][z] = dv + B[y][x];
                que.push({dv+B[y][x], {x, y+1, z}});
            }
            //rize
            if(dist[y][x][z+1] > dv + 1){
                dist[y][x][z+1] = dv + 1;
                que.push({dv+1, {x,y,z+1}});
            }
        }
        //天空
        else{
            //up
            if(y and dist[y-1][x][z] > dv + B[y][x]){
                dist[y-1][x][z] = dv + 1;
                que.push({dv+1, {x, y-1, z}});
            }
            //fall
            if(dist[y][x][z-1] > dv){
                dist[y][x][z-1] = dv;
                que.push({dv, {x,y,z-1}});
            }
        }
    }
    cout << dist[H-1][W-1][0] << ln;
}
