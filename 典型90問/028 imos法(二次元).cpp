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
二次元いもす
どこに足してどこに引くのかめっちゃ間違えた
*/


int main(){
    int N; cin >> N;
    int paper[1010][1010]{};
    rep(i, N){
        int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
        paper[lx][ly]++;
        paper[rx][ry]++;
        paper[lx][ry]--;
        paper[rx][ly]--;
    }

    //tate
    rep(i, 1009){
        rep(j, 1009){
            paper[i+1][j] += paper[i][j];
        }
    }
    //yoko
    rep(j, 1009){
        rep(i, 1009){
            paper[i][j+1] += paper[i][j];
        }
    }

    vector<int> ans(N+1);

    rep(i, 1010){
        rep(j, 1010){
            ans[paper[i][j]]++;
        }
    }

    rept(i, 1, N+1)cout << ans[i] << ln;
}
