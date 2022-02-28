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

vector<pll> prime_factorize(ll N){
    vector<pll> res;
    for(ll a=2; a*a<=N; a++){
        if(N%a != 0)continue;
        ll ex = 0;

        while(N%a==0){
            ex++;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if(N != 1)res.push_back({N, 1});
    return res;
}

/*
「modの条件下でLCMをどう求めるか」という問題。
直感的にA*BはLCM(A)である、とわかり、実際正解である。

gcdを使った求め方は約数が求まらないので使えない。
そこで、素因数分解を行って各指数の最大値を掛け合わせ方式を採る。
LCMの性質を学べる教育的な問題だと思う。
計算時間はO(10e4*10e3=10e7)くらい。
*/

const int MAX_A = 1e6;

int main(){
    int N; cin >> N;
    V<mint> A(N);
    V<int> E(MAX_A); //各素数ごとの最大指数
    rep(i, N){
        ll a; cin >> a; A[i] = a;
        auto vp = prime_factorize(a);
        for(auto P: vp){
            int p = P.first, e = P.second;
            chmax(E[p], e);
        }
    }
    //LCMを求める
    mint LCM = 1;
    rep(i, MAX_A){
        if(E[i]>0)LCM *= modpow(i, E[i]);
    }
    //ΣL/Aiを求める
    mint res = 0;
    for(auto a: A){
        res += LCM / a;
    }
    cout << res << ln;
}
