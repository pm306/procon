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


ll state[3030][5];
int main(){
    int n; cin >> n;
    rep(i, n)rep(j, 5)cin >> state[i][j];

    auto check = [&](int x) -> bool{
        bool exist[32]{};
        rep(i, n){
            int bit = 0;
            rep(j, 5)if(state[i][j] >= x)bit += 1<<j;
            exist[bit] = true;
        }

        rep(i, 32){
            rep(j, 32){
                rep(k, 32){
                    if((i | j | k) != 31)continue;
                    if(exist[i] and exist[j] and exist[k])return true;
                }
            }
        }

        return false;
    };

    int lo = 0, hi = 1<<30;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(check(mid))lo = mid;
        else hi = mid;
    }
    cout << lo << ln;
}
