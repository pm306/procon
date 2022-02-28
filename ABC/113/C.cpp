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

/*
座標圧縮そのものな問題。
グループ(県)ごとに並べ直してインデックスを取得する。
*/

string cityNumber(int p, int y){
    string s = to_string(p), t = to_string(y);
    while(s.size()<6)s = "0" + s;
    while(t.size()<6)t = "0" + t;
    return s + t;
}

int main(){
    int N, M; cin >> N >> M;
    vector<int> P(M), Y(M);
    rep(i, M)cin >> P[i] >> Y[i];

    vector<int> X[101010];
    rep(i, M)X[P[i]].push_back(Y[i]);
    rept(i, 1, N+1)sort(all(X[i]));

    rep(i, M){
        int y = lower_bound(all(X[P[i]]), Y[i]) - X[P[i]].begin() + 1;
        cout << cityNumber(P[i], y) << ln;
    }
}
