#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
基本的なグリッド探索問題
実装でミスらないように。
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp
*/

const int dx[8] = {1,1,1,0,0,-1,-1,-1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};

int main(){
    while(true){
        int W, H; cin >> W >> H;
        if(!W and !H)break;
        vector<vector<int>> grid(H, vector<int>(W));
        rep(i, H){
            rep(j, W){
                cin >> grid[i][j];
            }
        }

        int res = 0;
        vector<vector<int>> seen(H, vector<int>(W));
        auto dfs = [&](auto&& self, int y, int x) -> void{
            seen[y][x] = true;
            rep(k, 8){
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(ny<0 or ny>=H or nx<0 or nx>=W)continue;
                if(!grid[ny][nx] or seen[ny][nx])continue;
                self(self, ny, nx);
            }
        };
        rep(i, H){
            rep(j, W){
                if(!grid[i][j] or seen[i][j])continue;
                res++;
                dfs(dfs, i, j);
            }
        }
        cout << res << ln;
    }
}
