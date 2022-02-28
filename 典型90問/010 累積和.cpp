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
    int N; cin >> N;
    vector sum(2, vector<int>(N+1));
    rep(i, N){
        int c, p; cin >> c >> p; c--;
        sum[c][i+1] += p;
        rep(j, 2)sum[j][i+1] += sum[j][i];
    }

    vector<pair<int, int>> ans;
    int Q; cin >> Q;
    while(Q--){
        int l, r; cin >> l >> r; l--;
        ans.emplace_back(sum[0][r]-sum[0][l], sum[1][r]-sum[1][l]);
    }

    for(auto [a,b]:ans)printf("%d %d\n", a, b);
}
