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

/*
【重要な性質】
・頂点数curで、操作Aを行った場合の連結成分数はgcd(cur, A)

一度操作を行ったら、連結成分数を操作後のNとして問題内
*/

using pll = pair<ll, ll>;

int main(){
    int N, M; cin >> N >> M;
    vector<pll> CA;
    rep(i, M){
        ll a, c; cin >> a >> c;
        CA.emplace_back(c, a);
    }
    sort(all(CA));

    int cur = N;
    ll res = 0;
    for(auto [c, a]:CA){
        res += (cur - gcd(cur, a)) * c;
        cur = gcd(cur, a);
    }
    if(cur == 1)cout << res << ln;
    else cout << -1 << ln;
}


