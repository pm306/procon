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

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using tup = tuple<ll, int, int, int>; //cost, y, x, z

ll A[550][550], B[550][550];
int main(){
    int h, w; cin >> h >> w;
    rep(i, h)rep(j, w-1)cin >> A[i][j];
    rep(i, h-1)rep(j, w)cin >> B[i][j];

    min_priority_queue<tup> que;
    ll dist[550][550][2]; rep(i, h)rep(j, w)rep(k, 2)dist[i][j][k] = INF;
    que.emplace(0, 0, 0, 0);
    dist[0][0][0] = 0;

    while(que.size()){
        auto [cost, y, x, z] = que.top(); que.pop();
        if(cost > dist[y][x][z])continue;

        if(z == 0){
            //left
            if(x and chmin(dist[y][x-1][z], cost + A[y][x-1]))que.emplace(dist[y][x-1][z], y, x-1, z);
            //right
            if(x < w-1 and chmin(dist[y][x+1][z], cost + A[y][x]))que.emplace(dist[y][x+1][z], y, x+1, z);
            //down
            if(y < h-1 and chmin(dist[y+1][x][z], cost + B[y][x]))que.emplace(dist[y+1][x][z], y+1, x, z);
            //rise
            if(chmin(dist[y][x][1], cost + 1))que.emplace(dist[y][x][1], y, x, 1);
        }
        else{
            //up
            if(y and chmin(dist[y-1][x][z], cost + 1))que.emplace(dist[y-1][x][z], y-1, x, z);
            //fall
            if(chmin(dist[y][x][0], cost))que.emplace(dist[y][x][0], y, x, 0);
        }
    }

    cout << dist[h-1][w-1][0] << ln;
}
