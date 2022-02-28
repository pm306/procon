#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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
    Monoid get(int a){return dat[a+SIZE_R];}

    /* a,bの区間の最適値を求める */
    Monoid query(int a, int b) {
        Monoid vleft = UNITY, vright = UNITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright);

        }
        return F(vleft, vright);
    }
    inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

    /* デバッグ 葉の値を科出力する */
    void print() {
        for (int i = 0; i < SIZE_R; ++i) {
            cout << (*this)[i];
            if (i != SIZE_R-1) cout << ",";
        }
        cout << endl;
    }
};

int main(){
    int N, Q; cin >> N >> Q;
    SegTree<int> seg(N, [](int a, int b){return a ^ b;}, 0);
    rep(i, N){
        int a; cin >> a;
        seg.set(i, a);
    }
    seg.build();

    vector<int> ans;
    while(Q--){
        int T, X, Y; cin >> T >> X >> Y; X--;
        if(T==1){
            int num = seg.get(X) ^ Y;
            seg.update(X, num);
        }
        else{
            int res = seg.query(X, Y);
            ans.push_back(res);
        }
    }
    for(auto a: ans){
        cout << a << ln;
    }
}
