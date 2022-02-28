#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
3重→2重ループ系の全探索問題
条件が頭に入りづらかった。
sen_numが負になるケースに注意
*/

int main(){
    int N, Y; cin >> N >> Y;

    vector<int> ans{-1,-1,-1};
    rep(a, N+1){
        rep(b, N+1){
            int val = a * 10000 + b * 5000;
            int sen_num = N - (a + b);
            if(sen_num >= 0 and sen_num * 1000 == Y - val){
                ans[0] = a; ans[1] = b; ans[2] = sen_num;
            }
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << ln;
}
