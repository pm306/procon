#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1<<30;
constexpr long long LINF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
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
    friend constexpr Fp<MOD> modinv(const Fp<MOD> &a) noexcept{
        return modpow(a, MOD-2);
    }
};

using mint = Fp<MOD>;

mint dp[1<<25];
int x[26]; //x[i]:=値iが置かれている場所
int main(){
    vector<int> G;//まだ置かれてない座標

    rep(i, 25){
        int a; cin >> a;
        if(a==0)G.push_back(i);
        else x[a] = i+1;
    }

    dp[0] = 1;
    rep(mask, 1<<25){
        if(dp[mask] == 0)continue;
        int b = __builtin_popcount(mask) + 1; //次に置く数
        if(x[b]){//既に置かれている
            int r = x[b] - 1; //座標 一度 +1 して条件判定に使ってから-1してる？
            int X = r / 5, Y = r % 5;
            if(!(mask>>r&1)){
                if(X > 0 and X < 4 and ((mask>>(r-5)) ^ (mask>>(r+5))) & 1)continue; //上下片方に存在
                if(Y > 0 and Y < 4 and ((mask>>(r-1)) ^ (mask>>(r+1))) & 1)continue; //左右片方に存在
                dp[mask | (1<<r)] += dp[mask];
            }
        }
        else{ //まだ置かれてない
            rep(j, G.size()){//開いてるマス全部試す
                int r = G[j], X = r / 5, Y = r % 5;
                if(!(mask>>r&1)){
                    if(X > 0 and X < 4 and ((mask>>(r-5)) ^ (mask>>(r+5))) & 1)continue; //上下片方に存在
                    if(Y > 0 and Y < 4 and ((mask>>(r-1)) ^ (mask>>(r+1))) & 1)continue; //左右片方に存在
                    dp[mask | (1<<r)] += dp[mask];
                }
            }
        }
    }
    cout << dp[(1<<25)-1] << ln;
}
