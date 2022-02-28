

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

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,-1,1};
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using tup = tuple<int, int, int>;

int main(){
    int h, w; cin >> h >> w;
    vector<string> g(h); rep(i, h)cin >> g[i];

    min_priority_queue<tup> que; que.emplace(0, 0, 0);
    vector  dist(h, vector<int>(w, 1<<30)); dist[0][0] = 0;
    while(que.size()){
        auto [c, y, x] = que.top(); que.pop();
        if(c > dist[y][x])continue;

        rep(k, 4){
            int ny = y+dy[k], nx = x+dx[k];
            if(ny<0 or ny>=h or nx<0 or nx >= w)continue;
            if(g[ny][nx]=='.'){
                if(chmin(dist[ny][nx], c))que.emplace(c, ny, nx);
            }
            else{
                rept(i, max(0, ny-1), min(h, ny+2))rept(j, max(0, nx-1), min(w, nx+2)){
                    if(chmin(dist[i][j], c+1))que.emplace(c+1, i, j);
                }
            }
        }
    }
    cout << dist[h-1][w-1] << ln;
}
