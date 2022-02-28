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
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> using V = vector<T>;

/*
一瞬どうしていいか分からなかった

0(1)の数が偶数か奇数かで分ける。

正答数の差が偶数個なら正解数を一致させることができる(例1)。逆も同じ。
i問目を見た時、二人の解答が異なる(どちらかが1で、もう片方が0のとき。即ち1の数の偶奇が反転するとき)場合、正答数の差が奇数になる。
よって、二人の1or0の偶奇が異なるとき、必ず不一致になると言える。
*/

int main(){
    int N, M; cin >> N >> M;
    ll odd = 0, even = 0;
    rep(i, N){
        string s; cin >> s;
        if(whole(count, s, '0') % 2 == 0)even++;
        else odd++;
    }

    cout << even * odd << ln;
}
