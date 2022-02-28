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


int main(){
    int N; cin >> N;
    map<ll, ll> mp;
    ll sum = 0;
    rep(i, N){
        ll a; cin >> a;
        mp[a]++;
        sum += a;
    }

    int Q; cin >> Q;
    vector<ll> ans;
    while(Q--){
        ll b, c; cin >> b >> c;
        ll cnt = mp[b];
        sum -= cnt * b;
        mp[b] = 0;
        sum += cnt * c;
        mp[c] += cnt;
        ans.push_back(sum);
    }
    for(auto& a:ans)cout << a << ln;
}
