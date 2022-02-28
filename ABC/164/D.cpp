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
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    string s; cin >> s;
    vector<ll> cnt(2020);
    ll cur = 0, fac = 1;
    cnt[cur]++;
    rrep(i, s.size()){
        cur = (cur + fac * (s[i] - '0')) % 2019;
        fac = (fac * 10) % 2019;
        cnt[cur]++;
    }

    ll res = 0;
    fore(a, cnt)res += a * (a-1) / 2;
    cout << res << ln;
}

