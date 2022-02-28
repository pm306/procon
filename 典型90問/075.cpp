#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using pll = pair<ll, ll>;

vector<pll> prime_factorize(ll N){
    vector<pll> res;
    for(ll a=2; a*a<=N; a++){
        if(N%a != 0)continue;
        ll ex = 0;

        while(N%a==0){
            ex++;
            N /= a;
        }
        res.emplace_back(a, ex);
    }
    if(N != 1)res.emplace_back(N, 1);
    return res;
}

int main(){
    ll N; cin >> N;
    auto v = prime_factorize(N);
    int cnt = 0;
    for(auto& [p, e]:v)cnt += e;
    int res = 0, num = 1;
    while(num < cnt){
        num *= 2;
        res++;
    }
    cout << res << ln;
}


