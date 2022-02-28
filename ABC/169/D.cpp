#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
素因数分解して、指数の数を見る問題
今見ると簡単
*/

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

int main(){
    ll N; cin >> N;
    auto soinsu = prime_factorize(N);

    int res = 0;
    for(auto so:soinsu){
        int p = so.first, e = so.second;
        for(int i=1; e-i>=0; i++){
            res++;
            e -= i;
        }
    }
    cout << res << ln;
}
