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

using tup = tuple<ll, ll, ll>; //a*2+b, a, b;

int main(){
    int n; cin >> n;

    ll aoki = 0, takahashi = 0;
    priority_queue<tup> que;
    rep(i, n){
        ll a, b; cin >> a >> b;
        que.emplace(a*2+b, a, b);
        aoki += a;
    }

    int cnt = 0;
    while(que.size()){
        cnt++;
        auto [s, a, b] = que.top(); que.pop();
        aoki -= a;
        takahashi += a + b;
        if(aoki < takahashi)break;
    }
    cout << cnt << ln;
}

