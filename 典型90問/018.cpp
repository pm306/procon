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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int Q;
long double T, L, X, Y, E;
long double PI = 3.14159265358979;

long double query(long double I){
    long double cx = 0;
    long double cy = -(L / 2.0) * sin(I / T * 2.0 * PI);
    long double cz = (L / 2.0) - (L / 2.0) * cos(I / T * 2.0 * PI);
    long double d1 = sqrt((cx - X) * (cx - X) + (cy - Y) * (cy - Y));
    long double d2 = cz;
    long double kaku = atan2(d2, d1);
    return kaku * 180.0L / PI;
}

int main(){
    cin >> T >> L >> X >> Y >> Q;
    while(Q--){
        cin >> E;
        cout << fixed << setprecision(12);
        cout << query(E) << ln;
    }
}
