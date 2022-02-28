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

/*
両端の差だけに着目すれば良い
……のだが、配列saの定義と添え字をしっかり検証しなかったので大変なことになった
*/

int main(){
    int N, Q; cin >> N >> Q;
    vector<ll> A(N), sa(N-1);
    ll sum = 0;
    rep(i, N){
        cin >> A[i];
        if(i){
            sa[i-1] = A[i] - A[i-1];
            sum += abs(sa[i-1]);
        }
    }

    vector<ll> ans;
    while(Q--){
        ll l,r,v;cin >> l >> r >> v; l-=2, r--;
        if(l>=0){
            sum -= abs(sa[l]);
            sa[l] += v;
            sum += abs(sa[l]);
        }
        if(r<N-1){
            sum -= abs(sa[r]);
            sa[r] -= v;
            sum += abs(sa[r]);
        }
        ans.push_back(sum);
    }
    for(auto a:ans)cout << a << ln;
}
