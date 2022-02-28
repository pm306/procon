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
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
・位置関係のみが重要→座標の並行移動
・対称性→ゴール地点の回転

・パリティが同じグリッドは2回で必ず移動できるし、パリティが違えば移動できない
・2回の移動パターンは3種類。
・ナナメ→縦横　のパターンでは、まずy座標を合わせてからx座標の差が3以下であれば到達可能、と判定する

*/

int main(){
    ll a, b, c, d; cin >> a >> b >> c >> d;

    ll p = abs(c-a), q = abs(d-b);

    if(p==0 and q==0)cout << 0 << ln;
    else if(p+q <= 3 or p == q)cout << 1 << ln;
    else if(p+q <= 6 or (p+q)%2 == 0 or abs(p-q) <= 3)cout << 2 << ln;
    else cout << 3 << ln;
}

