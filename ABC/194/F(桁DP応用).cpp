#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) v += MOD;
}
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
}
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
}
constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
}
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
    }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
}
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
         return is >> x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

using mint = Fp<MOD>;

/*
桁DPの難しい版
dp[i][j]: i桁目まで見て「未満フラグが立っていて」「全て0ではなく」「先頭の0以外にj種類の数字を含む」場合の数
条件多くない？

遷移
1,2は途中でテーブルに参戦する感じ。
１：直前まで0が並び、i+1桁目で初めて0以外に遷移する。1~Fの15パターン
２：直前までNと同一で、i+1桁目で初めてN未満に遷移する。
    Nのi桁目までの出現文字は決まっているのでmaskで管理して、[0~N[i+1]-1]の範囲で論理和を取って遷移する。
    ただし初桁のみ0を採用できない（テーブルの制約に反するので）
３：今まで使った数字と同じ数字を使う。dp[i][j] * j通り。遷移先はdp[i+1][j]。
４：今まで使ってない数字をあらたに使う。dp[i][j] *(16-j)通り。遷移先はdp[i+1][j+1]。

dp[N.size][K]は1~N-1を対象としているので、N自体がK種類なら最後に加える。
*/

mint dp[202020][20];
int main(){
    string N; int K; cin >> N >> K;
    int mask = 0; //Nに使用された数字のマスクビット

    rep(i, N.size()){
        char c = N[i]; int y;
        if(c>='A' and c<='F')y=10+c-'A';
        else y=(c-'0');

        //直前まで(1つ以上の)0,初めて0以外の数字が出る
        if(i>0)dp[i+1][1] += 15;
        //直前までNと同一、初めてN未満になる
        rep(j, y){
            if(i==0 and j==0)continue; //初桁のみ0は選べない
            int x = __builtin_popcount(mask | 1<<j); //数字jを採用したときの種類数
            dp[i+1][x] += 1;
        }
        //その他
        rep(j, 17){
            dp[i+1][j] += dp[i][j] * j;
            dp[i+1][j+1] += dp[i][j] * (16 - j);
        }
        mask |= (1<<y);
    }

    mint res = dp[N.size()][K];
    if(__builtin_popcount(mask)  == K)res += 1;
    cout << res << ln;
}
