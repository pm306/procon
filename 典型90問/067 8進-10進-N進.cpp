#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

string base_10_to_n(ll X, int n){
    if(X/n)return base_10_to_n(X/n, n) + to_string(X%n);
    return to_string(X%n);
}

string func(string n){
    ll a;
    istringstream(n) >> oct >> a;
    string res = base_10_to_n(a, 9);
    for(auto& r:res)if(r=='8')r='5';
    return res;
}

int main(){
    string N; int K; cin >> N >> K;
    string res = N;
    while(K--){
        res = func(res);
    }
    cout << res << ln;
}
