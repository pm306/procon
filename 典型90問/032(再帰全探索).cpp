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
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    int A[10][10]{}; rep(i, n)rep(j, n)cin >> A[i][j];

    int m; cin >> m;
    int B[10][10]{};
    rep(i, m){
        int x, y; cin >> x >> y; x--, y--;
        B[x][y] = B[y][x] = -1;
    }

    ll res = INF;
    auto dfs = [&](auto dfs, vector<int> pat) -> void{
        if(pat.size() == n){
            ll cost = 0;
            rep(i, n) cost += A[pat[i]][i];
            chmin(res, cost);
            return;
        }

        rep(next, n){
            if(pat.empty() or find(all(pat), next) == pat.end() and B[pat.back()][next] != -1){
                pat.push_back(next);
                dfs(dfs, pat);
                pat.pop_back();
            }
        }
    };

    vector<int> pat;
    dfs(dfs, pat);
    cout << (res == INF ? -1 : res) << ln;
}
