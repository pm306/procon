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
https://shindannin.hatenadiary.com/entry/2015/12/23/223251
↑図が明解です　要チェック

累積和テーブルをi~K-i連続停車としていてわかりやすい
n駅連続停車 = 最後に止まってない駅がn-1駅前

https://docs.google.com/document/d/16DzHzl7kyIuKJn_K8IBt5IfHzMmpxQ-LrrWmPGbGXtU/edit
dpの次元削減について触れられている
まず dp[i][0] = dp[i-1][0] + ... + dp[i-1][k-1] ←区間和で何とかなりそう感
dp[i][j] = dp[i-1][j-1] とあるように、1<=j<=K-1 において遷移が同じような1通りしかない
↓
dp[i-j][0] = dp[i][j] とすることで、jを使わずにj>0の遷移を得ることができる! すごい
よって
dp[i] = dp[i-1] + dp[i-2] + ... + dp[i-k]
これを尺取り法的に１つずつずらしていけば、i>2について
dp[i] = sum[0,i) - sum[0,i-k)
答えはSUM[N]
*/

mint dp[1000100], S[1000100];
int main(){
    int N, K; cin >> N >> K;

    //dp[n]:n駅まできて、現在0連続停車
    //S[i]:n駅まできて、現在1～K-1連続停車
    dp[0] = S[1] = 1;
    for(int i=1; i<N; i++){
        dp[i+1] = S[i] + dp[i];
        S[i+1] = S[i] + dp[i] - (i-K+1 >= 0 ? dp[i-K+1] : 0);
    }
    cout << S[N] << ln;
}
