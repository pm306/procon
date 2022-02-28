#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> using V = vector<T>;

/*
考察60%くらいまでいって投げた。
Lcst, Rcst：常に、現在西端/東端にいる時の最小距離の両方を持ち続け、最後に比較すれば良い。
最適動作は
「今東端にいて、次も東端で動作が終わる」
「今西端にいて、次は東端で動作が終わる」//ここまでLcst2
「今東端にいて、次は西端で動作が終わる」
「今西端にいて、次も西端で動作が終わる」//ここまでRcst2
の4通りしかない。（検証ミスってこの可能性を捨ててしまった。貪欲が通るかどうかの判定はむずかしい）

Lcst2とRcst2を求めたらそれをLcst, Rcstとし、東端と西端も更新を更新し続ける。

同色の最小値と最大値は素直に連想配列内の配列をループでチェックすれば間に合った。
*/

int main(){
    int N; cin >> N;
    V<int> X(N), C(N); rep(i, N)cin >> X[i] >> C[i];

    //色ごとの座標を連想配列内の配列で持つ。最大値、最小値は後で調べる
    map<int, V<int>> mp;
    rep(i, N)mp[C[i]].push_back(X[i]);


    int L = 0, R = 0;
    //西端、東端にいるときの移動距離の最小値。
    ll Lcst = 0, Rcst = 0;
    for(auto p: mp){
        //mi:西端　ma:東端
        int mi = INF, ma = -INF;
        for(auto x: p.second){
            chmin(mi, x);
            chmax(ma, x);
        }

        int L2 = mi, R2 = ma; //次の初期地点候補。西端、東端のどちらか
        ll Lcst2 = LINF, Rcst2 = LINF;//次の最小移動距離候補。

        //L -> L2 -> R2
        chmin(Rcst2, Lcst + abs(L-L2) + abs(L2-R2));
        //L -> R2 -> L2
        chmin(Lcst2, Lcst + abs(L-R2) + abs(R2-L2));
        //R -> L2 -> R2
        chmin(Rcst2, Rcst + abs(R-L2) + abs(L2-R2));
        //R -> R2 -> L2
        chmin(Lcst2, Rcst + abs(R-R2) + abs(R2-L2));

        L = L2, R = R2, Lcst = Lcst2, Rcst = Rcst2;
    }

    ll res = min(Lcst + abs(L), Rcst + abs(R));
    cout << res << ln;
}
