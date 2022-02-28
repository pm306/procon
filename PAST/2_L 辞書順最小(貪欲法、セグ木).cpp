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
    int N, K, D; cin >> N >> K >> D;
    vector<ll> A(N), ans(K);
    rep(i, N){
        cin >> A[i];
    }

    auto comp_pair_min = [](pair<long long, long long> a, pair<long long, long long> b) -> pair<long long, long long>{
        if(a.first < b.first or a.first == b.first and a.second < b.second){
            return a;
        }else{
            return b;
        }
    };
    SegTree<pll> seg(N, comp_pair_min, {INF, INF});
    rep(i, N)seg.set(i, {A[i], i});
    seg.build();

    int idx = 0;
    rep(k, K){
        int rest = K - k; //選ぶ必要のある値の個数

        //左端、右端[L, R]
        int L = idx, R = N - 1 - ((rest-1) * D);
        if(R < L){
            cout << -1 << ln;
            return 0;
        }
        auto p = seg.get(L, R+1);
        ans[k] = p.first;
        idx = p.second + D;
    }

    for(auto a:ans)cout << a << " "; cout << ln;
}
