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



int main(){

    int N, M, Q; cin >> N >> M >> Q;
    vector<pll> nimotu(N); //value, weight
    rep(i, N){
        ll w, v; cin >> w >> v;
        nimotu[i] = {v, w};
    }
    sort(all(nimotu), greater<pll>());
    vector<ll> X(M); rep(i, M)cin >> X[i];

    vector<ll> ans;
    while(Q--){
        int L, R; cin >> L >> R; L--; //[L, R)
        vector<ll> box;
        rep(i, M){
            if(i<L or i>= R)box.push_back(X[i]);
        }
        sort(all(box));

        ll res = 0; vector<int> used(N);
        rep(i, box.size()){
            rep(j, N){
                if(used[j])continue;
                if(nimotu[j].second <= box[i]){
                    res += nimotu[j].first;
                    used[j] = true;
                    break;
                }
            }
        }
        ans.push_back(res);
    }
    for(auto a:ans)cout << a << ln;
}
