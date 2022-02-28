#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n, k; cin >> n >> k;
    vector<int> P(n); rep(i, n) cin >> P[i];

    //出目がp種類あるサイコロの出目の期待値
    auto exval = [&](int p) -> double{
        return ((p * (p+1))/2) / (double)p;
    };

    double res = 0, val = 0; //val:期待値
    rep(i, n){
        //初期処理
        if(i<k){
            val += exval(P[i]);
        }
        //遷移
        else{
            val += exval(P[i]);
            val -= exval(P[i-k]);
        }
        chmax(res, val);
    }
    cout << fixed << setprecision(12);
    cout << res << ln;
}
