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
問題文が直感的にわかりづらいが、累積和的な高速化を図る問題。

各aについて、aが自身より手前の全ての値より小さいかどうかを調べる。
min{A[0]~A[i-1]} > A[i] と言い換えられるので、各ステップごとに最小値を更新しつつ比較すればO(N)で計算でき、間に合う。
ステップごとの変化が限定的であることに着目するという意味では、累積和に近い考え方と言えるかも。

実装については特になし。
ちなみにAは順列になっているが、特に利用しない。紛らわしい。
*/

int main(){
    int N; cin >> N;

    int res = 0;
    int minA = INF;
    rep(i, N){
        int a; cin >> a;
        if(minA > a)res++;
        chmin(minA, a);
    }
    cout << res << ln;
}
