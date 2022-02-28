#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MOD = 2019;

int power10[202020];
void init10() {
    power10[0] = 1;
    for (int i = 1; i <= 200020; i++) power10[i] = (10LL * power10[i - 1]) % MOD;
}

int main(){
    string S; cin >> S;
    int n = S.size();

    init10();
    vector<int> V(n), sum(n+1);
    rep(i, n){
        V[i] = (S[i]-'0') * power10[n-1-i] % MOD;
        sum[i+1] = (sum[i] + V[i]) % MOD;
    }

    ll res = 0;
    vector<int> cnt(2030);
    rep(i, n+1){
        res += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    cout << res << ln;
}



