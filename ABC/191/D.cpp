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
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    long double X, Y, R; cin >> X >> Y >> R;

    //(x,y)と中心点の距離がR以下か
    auto check = [&](int x, int y) -> bool{
        long double dist = (x - X) *(x - X) + (y - Y) * (y - Y);
        //distがR*Rと等しい場合でも、誤差でほんの少し大きくなる可能性がある
        return dist - EPS <= R * R;
    };

    ll res = 0;
    for(int y=floor(Y+R+EPS); y>=ceil(Y-R-EPS); y--){
        //left ※格子点が存在しない場合もある
        ll ng = -INF, ok = floor(X+EPS) + 1;
        while(ok-ng>1){
            ll mid = (ok+ng)/2;
            if(check(mid, y))ok=mid;
            else ng=mid;
        }
        //right
        ll okr = ceil(X-EPS) - 1, ngr = INF;
        while(ngr-okr>1){
            ll mid = (okr+ngr)/2;
            if(check(mid, y))okr=mid;
            else ngr=mid;
        }
        //0個のときは交差
        res += okr - ok + 1;
    }
    cout << res << ln;
}
