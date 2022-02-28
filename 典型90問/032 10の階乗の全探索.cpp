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
なんか間に合わなさそうだけど枝狩りされるので間に合う

険悪フラグは事前にメモっておくと早い
*/

int main(){
    int N; cin >> N;
    int A[10][10]; rep(i, N)rep(j, N)cin >> A[i][j];
    int M; cin >> M;
    int kenaku[10][10]{};
    rep(i, M){
        int x, y; cin >> x >> y, x--, y--;
        kenaku[x][y] = true;
        kenaku[y][x] = true;
    }

    vector<int> NP(N);
    rep(i, N)NP[i] = i;
    auto check = [&]() -> bool {
        rep(i, N-1){
            if(kenaku[NP[i]][NP[i+1]])return false;
        }
        return true;
    };
    ll res = LINF;
    do {
        if(check()){
            ll cost = 0;
            rep(i, N)cost += A[NP[i]][i];
            chmin(res, cost);
        }
    } while(next_permutation(NP.begin(), NP.end()));
    if(res==LINF)res = -1;
    cout << res << ln;
}
