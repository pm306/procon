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
セグ木+DP
区間最大値を対数時間で引っ張って遷移する
テーブルを削減する都合上後ろから見るのと、chmaxが使えないことに注意
*/

/* 抽象化セグメントツリー (1-used) */
template<class Monoid> struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func F;
    const Monoid UNITY;
    int SIZE_R;
    vector<Monoid> dat;

    /* コンストラクタ n:要素数  f:比較関数  unity:初期値 */
    SegTree(int n, const Func f, const Monoid &unity): F(f), UNITY(unity) { init(n); }
    void init(int n) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, UNITY); //※1スタート
    }

    /* a番目の値にvを設定する */
    void set(int a, const Monoid &v) { dat[a + SIZE_R] = v; }
    /* 木を構築する */
    void build() {
        for (int k = SIZE_R - 1; k > 0; --k)
            dat[k] = F(dat[k*2], dat[k*2+1]);
    }

    /* a番目の値をvに更新する */
    void update(int a, const Monoid &v) {
        int k = a + SIZE_R;
        set(a, v);
        while (k >>= 1){
            dat[k] = F(dat[k*2], dat[k*2+1]);
        }
    }

    /* a番目の値を取得する */
    Monoid val(int a){return dat[a+SIZE_R];}

    /* a,bの区間の最適値を求める */
    Monoid get(int a, int b) {
        Monoid vleft = UNITY, vright = UNITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright);

        }
        return F(vleft, vright);
    }
    inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

    /* デバッグ  */
    void print() {
        for (int i = 0; i < SIZE_R; ++i) {
            cout << (*this)[i];
            if (i != SIZE_R-1) cout << ",";
        }
        cout << endl;
    }
};

int main(){
    int W, N; cin >> W >> N;
    int L[550], R[550]; ll V[550];
    rep(i, N)cin >> L[i] >> R[i] >> V[i];

    SegTree<ll> dp(W+1, [](ll a, ll b){return a > b ? a : b;}, -1);
    dp.set(0, 0);
    dp.build();
    rep(i, N){
        //dp.print();
        rrep(j, W){
            //L~R
            ll max_val = dp.get(max(0, j-R[i]), max(0, j-L[i]+1));
            if(max_val >= 0 and dp.val(j) < max_val + V[i]){
                dp.update(j, max_val + V[i]);
            }
        }
    }
    //dp.print();
    cout << dp.val(W) << ln;
}
