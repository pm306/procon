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
全探索すると間に合わないので、条件を満たす（満たさない）値だけを数え上げえる

計算量が不安になる
*/

int main(){
    ll N; cin >> N;

    map<ll, bool> mp;
    for(ll a=2; a*a<=N; a++){
        ll p = a;
        while(p*a<=N){
            p*=a;
            mp[p] = true;
        }
    }
    cout << N - mp.size() << ln;
}
