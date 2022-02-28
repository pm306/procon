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
#define rep(i,n) for(int i=0;i<(n);i++)
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
LCS的な部分文字列DP
二次元累積和で高速計算
累積DP+二次元累積和+編集距離、とてんこもりな問題

必ずしもDPテーブルで数え上げを行う必要はなく、別途累積和テーブルを持っている。
二次元なのでわかりにくいが、原理は一次元と同じ。
DP更新しながら累積和的なものを取っていくパターンは典型かもしれない。
*/

mint dp[2010][2010], sdp[2010][2010];
int main(){
    int n, m; cin >> n >> m;
    vector<int> S(n), T(m);
    rep(i, n)cin >> S[i];
    rep(i, m)cin >> T[i];

    dp[0][0] = sdp[1][1] = 1;
    //ループ回数が多い
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 and j==0)continue;
            //参照インデックスは-1される
            //必要な累積和は自身のマスの左上までなのでsdp[i+1][j+1]ではない
            if(i-1 >= 0 and j-1 >= 0 and S[i-1] == T[j-1]){
                dp[i][j] = sdp[i][j];
            }
            //動的に累積和を更新する
            sdp[i+1][j+1] = sdp[i+1][j] + sdp[i][j+1] - sdp[i][j] + dp[i][j]; 
        }
    }
    cout << sdp[n+1][m+1] << ln;
/*
    rep(i, n+1){
        rep(j, m+1){
            cout <<dp[i][j] << " ";
        }cout << ln;
    }

    rep(i, n+2){
        rep(j, m+2){
            cout << sdp[i][j] << " ";
        }cout << ln;
    }
*/
}   