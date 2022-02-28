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

//配列1つで済むからこの実装がベストかな

int R[2020][2020];
int main(){
    int H, W; cin >> H >> W;
    vector<string> g(H); rep(i, H)cin >> g[i];

    int cnt;
    //  左右
    rep(i, H){
        cnt = 0;
        rep(j, W){
            if(g[i][j]=='#')cnt = 0;
            else cnt++;
            R[i][j] += cnt;
        }
        cnt = 0;
        rrep(j, W){
            if(g[i][j]=='#')cnt = 0;
            else cnt++;
            R[i][j] += cnt;
        }
    }
    //上下
    rep(j, W){
        cnt = 0;
        rep(i, H){
            if(g[i][j]=='#')cnt = 0;
            else cnt++;
            R[i][j] += cnt;
        }
        cnt = 0;
        rrep(i, H){
            if(g[i][j]=='#')cnt = 0;
            else cnt++;
            R[i][j] += cnt;
        }
    }

    int res = 0;
    rep(i, H)rep(j, W)chmax(res, R[i][j] - 3);
    cout << res << ln;
}

