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

/*
不等号の式変形はめんどくさいので、2点を固定して考える
xの大きいほうを常にx2とし、y2-y1/x2-x1を求める
ペアの位置関係が逆のときはx,yをそれぞれ入れ替える
*/

int main(){
    int n; cin >> n;
    vector<ll> X(n), Y(n); rep(i, n)cin >> X[i] >> Y[i];

    int res = 0;
    rep(i, n){
        rept(j, i+1, n){
            ll b = Y[j]-Y[i], a = X[j]-X[i];
            if(a < 0)a = -a, b = -b;
            if(-a <= b and b <= a)res++;
        }
    }
    cout << res << ln;
}
