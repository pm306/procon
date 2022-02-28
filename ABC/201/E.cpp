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

/*
木が与えられる。頂点のペアすべてのdist(i, j)の総和をmodで求めよ

dist(i, j) = dist(r, i) XOR dist(r, j)である
重みを桁ごとに独立させて考えると、distは0or1の2種類しかない
よって、ある桁についてdist=0 の数と dist[1] の数を掛け合わせたものが答えとなる
*/

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

int main(){
    int N; cin >> N;
    vector<vector<pll>> G(N);
    rep(i, N-1){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    //bfs
    vector<ll> dist(N, -1);
    queue<int> que; que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        auto v = que.front(); que.pop();
        for(auto e: G[v]){
            ll nv = e.first, weight = e.second;
            ll sum = dist[v] ^ weight;
            if(dist[nv] == -1){
                dist[nv] = sum;
                que.push(nv);
            }
        }
    }

    mint res = 0;
    rep(i, 60){
        mint cnt[2]{};
        rep(j, N){
            cnt[dist[j]>>i&1] += 1; //二進数でj桁目が1のものを数える
        }
        res += (mint)(1ll<<i) * cnt[0] * cnt[1];
    }
    cout << res << ln;
}
