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

ll solve(){
    int M; cin >> M;
    vector<ll> P(50000); ll sum = 0;
    rep(i, M){
        int p, n; cin >> p >> n;
        P[p] = n;
        sum += p*n;
    }
    ll MAX = 0;
    for(int i=1; i<=49900; i++){
        auto insu = prime_factorize(i);
       // if(i==17)cout << insu.size() << ln;
        bool ok = true; ll add = sum, seki = 1;
        for(auto a:insu){
            ll p = a.first, n = a.second;
            //if(i==17)cout << "p:" << p << " n:" << n << ln;
            if(P[p] < n){ok = false;break;}
            add -= p * n;
            seki *= pow(p, n);
        }
        //if(i==17)cout << add << " " << seki << "!" << ln;
        if(!ok or add != seki)continue;
        chmax(MAX, add);
    }

    return MAX;
}

int main(){

    int T; cin >> T;
    vector<ll> ans;
    rep(t, T){
        ans.push_back(solve());
    }

    rep(i, ans.size()){
        cout << "Case #" << i+1 << ": " << ans[i] << ln;
    }

}
