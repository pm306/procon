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
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
純粋数学。
ベクトル回転。
複素数で回転すると楽なのでcomplex型を使っている。
*/

int main(){
    int N; cin >> N;
    complex<double> a, b;
    double x, y;
    cin >> x >> y; a = { x, y };
    cin >> x >> y; b = { x, y };

    auto m = (a + b) / 2.0; //中点

    //ベクトルの回転。複素数平面上でベクトル(x,y)を回転させたいとき、角度に対応する複素数を掛ければよい（理由は知らん）
    auto res = m + (a - m) * polar(1.0, M_PI*2.0/N); //polar:複素数を極形式で指定して作る。(絶対値、偏角)

    cout << fixed << setprecision(12);
    cout << res.real() << " " << res.imag() << ln;
}
