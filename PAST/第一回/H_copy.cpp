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

/*
1-indexedかつ、偶奇を扱う問題なのでややこしい。
ここでは0-indexedに読み替えている。

*/


ll N, C[202020], Q; //C:=単品販売だけした時の在庫
int main(){
    cin >> N;
    rep(i, N)cin >> C[i];
    cin >> Q;

    ll offset[2]{}; //offset:差引 偶数/奇数番目の商品の販売個数
    ll mi[2] = {INF, INF};
    rep(i, N)chmin(mi[i%2], C[i]);
    ll cnt[2]; cnt[1] = N / 2; cnt[0] = N - cnt[1]; //奇数はN/2個、偶数は(N+1)/2個

    ll res = 0;
    while(Q--){
        int t; cin >> t;
        if(t == 1){
            ll x, a; cin >> x >> a; x--;

            if(C[x] - offset[x%2] >= a){
                res += a;
                C[x] -= a;
                chmin(mi[x%2], C[x]);
            }
        }
        else if(t == 2){ //偶数のセット販売に読み替え
            ll a; cin >> a;
            if(mi[0] - offset[0] >= a){
                res += a * cnt[0];
                offset[0] += a;
            }
        }
        else{
            ll a; cin >> a;
            if(mi[0] - offset[0] >= a and mi[1] - offset[1] >= a){
                res += a * N;
                offset[0] += a;
                offset[1] += a;
            }
        }
    }
    cout << res << ln;
}
