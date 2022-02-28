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

int main(){
    int n; cin >> n;

    const string t = "MARCH";
    ll cnt[5]{};
    rep(i, n){
        string s; cin >> s;
        int idx = t.find(s[0]);
        if(idx!=-1)cnt[idx]++;
    }

    ll res = 0;
    rep(i, 5){
        rept(j, i+1, 5){
            rept(k, j+1, 5){
                res += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    cout << res << ln;
}

