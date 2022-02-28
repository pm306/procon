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
////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(){
    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> fri(n), bro(n);
    dsu uf(n);
    rep(i, m){
        int a, b; cin >> a >> b; a--, b--;
        fri[a].push_back(b);
        fri[b].push_back(a);
        uf.merge(a, b);
    }
    rep(i, k){
        int c, d; cin >> c >> d; c--, d--;
        bro[c].push_back(d);
        bro[d].push_back(c);
    }

    vector<int> ans(n);
    rep(i, n){
        ans[i] = uf.size(i) - fri[i].size() - 1;
        fore(b, bro[i])if(uf.same(i, b))ans[i]--;
    }
    fore(a, ans)cout << a << " ";
    cout << ln;
}
