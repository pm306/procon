#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 998244353;//1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
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
     friend constexpr Fp<MOD> inv(const Fp<MOD> &a) noexcept{
         return modpow(a, MOD-2);
     }
};

using mint = Fp<MOD>;

using mat = vector<vector<mint>>;
//A*B
mat mul(mat& A, mat&B){
    mat C(A.size(), vector<mint>(B[0].size()));
    for(int i=0; i<A.size(); i++){
        for(int k=0; k<B.size(); k++){
            for(int j=0; j<B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}

//A^n
mat pow(mat A, ll n){
    mat B(A.size(), vector<mint>(A.size()));
    for(int i=0; i<A.size(); i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if (n & 1) B = mul(B, A);
        A = mul(A, A); //Aを2乗
        n >>= 1;
    }
    return B;
}

ll H, W;
void dfs(auto& V, int from, int to, int pos){
    if(pos == H){
        V[to][from] += 1;
        return;
    }

    //使えない maskの右からpos個目が1　※覚える
    if(from>>pos & 1){
        dfs(V, from, to, pos+1);
    }
    //使える
    else{
        //下に一畳敷く
        if(pos != H-1 and !(from>>(pos+1) & 1)){
            dfs(V, from, pos+2,to);
        }
        //右に一畳敷く ※一番右端という概念はない
        dfs(V, from, to | 1<<pos ,pos+1);
        //半畳敷く
        dfs(V, from, to, pos+1);
    }
}

int main(){
    cin >> H >> W;
    int siz = 1<<H;

    mat V(siz, vector<mint>(siz));

    //列の状態を全部見る
    for(int mask=0; mask<siz; mask++){
        dfs(V, mask, 0, 0);
    }

    auto A = pow(V, W);
    cout << A[0][0] << ln;
}

