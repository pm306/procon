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

/**
 * 余弦定理
 * 弧度法と度数法
 * なんか360度超えてるけど通る。なんで？
 */

int main(){
    double A, B, H, M; cin >> A >> B >> H >> M;

    double time = H*60+M; //経過時間(分)
    double a = time*0.5, b = time*6; //長針、短針の角度
    double sita = min(abs(a-b), 360-abs(a-b)); //A,Bを含む三角形で作られる角の角度。
    double rad = sita * M_PI / 180; //cos関数はラジアン（弧度法）を引数に取るので変換　公式はググれば出る
    cout << a << " " << b << " " << sita << " " << rad << " " << ln;

    cout << fixed << setprecision(12);
    cout << sqrt(A*A + B*B - 2*A*B*cos(rad)) << ln; //余弦定理
}
