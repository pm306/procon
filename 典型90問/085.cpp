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
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<long long> yakusu_rekkyo(long long N){
    vector<long long> res;
    for(long long i=1; i*i<=N; i++){
        if(N%i==0){
            res.push_back(i);
            if(N/i!=i)res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    ll K; cin >> K;

    auto V = yakusu_rekkyo(K);
    ll res = 0;
    fore(a, V){
        fore(b, V){
            __int128 seki = a; seki *= b;
            if(seki > K)continue;
            if(K % (a * b) != 0)continue;
            ll c = K / (a * b);
            if(a <= b and b <= c)res++;
        }
    }
    cout << res << ln;
}

