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

int dx[4] = {0,1,0,1};
int dy[4] = {0,0,1,1};

int main(){
    int H, W; cin >> H >> W;
    vector<string> g(H); rep(i, H)cin >> g[i];

    int res = 0;
    rep(i, H-1){
        rep(j, W-1){
            int b = 0;
            rep(k, 4)if(g[i+dy[k]][j+dx[k]]=='#')b++;
            if(b%2==1)res++;
        }
    }
    cout << res << ln;
}
