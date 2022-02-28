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
    string X; ll M; cin >> X >> M;

    if(X.size()==1){
        if(M < (X[0]-'0'))cout << 0 << ln;
        else cout << 1 << ln;
        return 0;
    }


    int mx_x = -1;
    //xに含まれる最大の値
    for(auto x:X){
        chmax(mx_x, x-'0');
    }

    //数字列Xをval進数と見做したときの10進数での値 ※基数変換ではない
    auto check = [&](__int128_t val) -> bool{
        __int128_t num = 0;
        rep(i, X.size()){
            num *= val;
            num += (X[i]-'0');
            if(num > M)return false;
        }
        return num <= M;
    };

    //Xを基数変換してM以下になるかどうか
    ll ok = mx_x, ng = LINF;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << ok - mx_x << ln;
}
