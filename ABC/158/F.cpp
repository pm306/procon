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

using mint = modint998244353;
int op(int a, int b){return max(a, b);}
int e(){return -1;}

int main(){
    int n; cin >> n;
    vector<pair<int, int>> R(n); rep(i, n)cin >> R[i].first >> R[i].second;

    //step 1:座標の小さい順にソート
    //ソートすることで、連鎖するロボットを自分より右側に限定できる※重要
    sort(all(R));
    vector<int> X(n); rep(i, n)X[i] = R[i].first; //二分探索用の配列

    //step 2:各ロボットが作動した時に、連鎖的に作動するロボットの最右インデックスを求める
    segtree<int, op, e> seg(n);
    rep(i, n){
        int right = R[i].first + R[i].second;
        int range = lower_bound(all(X), right) - X.begin() - 1;
        seg.set(i, range);
    }

    //step 3:i番目のロボットが作動したとき、影響を受けるロボットの最大値を求める
    //後ろから見る(影響の少ないロボットから情報を確定させる)ことで、各ロボットの連鎖範囲がわかる
    //各iについてi～k番目のロボットが影響を与えるロボットの番号のうち最も大きいものを取得
    //直観的には、自分が点火したロボットのうち、最も影響範囲が広いものをsegTreeで取得している
    rrep(i, n){
        int right = seg.prod(i, seg.get(i)+1);
        seg.set(i, right);
    }

    //step 4:後ろからdp
    //dp[i] = dp[i+1] + dp[j]
    vector<mint> dp(n+1);
    dp[n] = 1; //全てのロボットを取り除いた場合
    rrep(i, n){
        int j = seg.get(i) + 1;
        dp[i] = dp[i+1] + dp[j];
    }
    cout << dp[0].val() << ln;
}

