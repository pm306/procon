#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
using vll = vector<long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int P[10][10101];
int main(){
	int H, W; cin >> H >> W;
    rep(i, H)rep(j, W)cin >> P[i][j];

    int res = 0;
    //H全探索
    for(int mask=1; mask<1<<H; mask++){
        //W全チェック
        vector<int> C(H*W+1);
        for(int j=0; j<W; j++){
            int num = 0;
            for(int i=0; i<H; i++){
                if(!(mask>>i & 1))continue;
                if(num != 0 and num != P[i][j])num = -1;
                else num = P[i][j];
            }
            if(num > 0)C[num]++;
        }
        int tate = __builtin_popcount(mask);
        int yoko = 0;
        for(auto& c:C)chmax(yoko, c);
        chmax(res, tate * yoko);
    }
    cout << res << ln;
}
