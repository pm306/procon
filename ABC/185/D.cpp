#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
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

ll getCeil(ll a, ll b){
    return (a + b - 1) / b;
}

int main(){
    ll N, M; cin >> N >> M;
    vector<ll> A(M);
    rep(i, M){
        cin >> A[i];
    }

    sort(all(A));
    A.push_back(N+1);

    ll bef = 0, k = N;
    vector<ll> v;
    rep(i, A.size()){
        ll haba = A[i] - bef - 1;
        if(haba)chmin(k, haba);
        v.push_back(haba);
        bef = A[i];
    }
    ll res = 0;
    for(auto a:v){
        res += getCeil(a, k);
    }
    cout << res << ln;
}
