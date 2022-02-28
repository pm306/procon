#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
貪欲に文字を選んでいく。(辞書順最小かつ一番左にあるもの)
ただし、必ずK文字選ばないといけないので、選べる文字の区間が制限される
そこでRMQを使う

1:選択可能な範囲[l,r)を決定する
l:= 直前に選んだ文字の次の文字
r:= 選ぶ必要がある文字数をrestとすると、後ろからrest-1文字は選べない
2:区間内で辞書順最小かつ最左にある文字をRMQで選ぶ
3:最後に選んだ文字の位置を更新する

セグ木の作り方 ※アルファベットを数字に変換してる
pair<アルファベット, 出現インデックス>
pairなのは同じアルファベットが複数ある時に最差のものを選ぶため。

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
    int N, K; cin >> N >> K;
    string S; cin >> S;

    auto comp_pair_min = [](pair<long long, long long> a, pair<long long, long long> b) -> pair<long long, long long>{
        if(a.first < b.first or a.first == b.first and a.second < b.second){
            return a;
        }else{
            return b;
        }
    };
    SegTree<pll> seg(N, comp_pair_min, {INF, INF});
    rep(i, N){
        seg.set(i, {S[i] - 'a', i}); //{アルファベット(0~25), インデックス}
    }
    seg.build();

    string res = "";
    int idx = 0;
    rep(i, K){
        int l = idx, r = (N-1) - (K-i-1) + 1;
        auto p = seg.get(l, r);
        res += (char)('a' + p.first);
        idx = p.second + 1;
    }
    cout << res << ln;
}
