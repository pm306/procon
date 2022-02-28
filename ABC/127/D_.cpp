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


int main(){
    int N, M; cin >> N >> M;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    vector<pair<ll, ll>> Q;
    rep(i, M){
        ll b, c; cin >> b >> c;
        Q.emplace_back(c, b);
    }

    sort(all(A));
    sort(all(Q), greater<pair<ll, ll>>());

    int idx = 0;
    for(auto& [c, b]:Q){
        while(b--){
            if(idx == N or A[idx] > c){
               goto END;
            }
            A[idx] = c;
            idx++;
        }
    }
    END:
        cout << accumulate(all(A), 0LL) << ln;
}

