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
    vector<ll> A(N); rep(i, N)cin >> A[i];

    //大きい順に並んだほうがよさそう
    sort(all(A), greater<ll>());

    ll res = 0;
    priority_queue<pll> que; //辺？
    que.push({A[1], A[0]});
    que.push({A[1], A[0]});
    res += A[0];

    for(int i=2; i<N; i++){
        auto p = que.top(); que.pop();
        res += min(p.first, p.second);
        que.push({A[i], p.first});
        que.push({A[i], p.second});
    }
    cout << res << ln;
}
