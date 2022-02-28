#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1<<30;
constexpr long long LINF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
小数演算の切り捨て　→　100倍した整数をかける→小数との整合性と取るために右に２つシフト(100で割った商を取る)
*/

int main(){
    int N; cin >> N;
    N *= 108; N /= 100;
    string res;
    if(N < 206)res="Yay!";
    else if(N==206)res="so-so";
    else res=":(";
    cout << res << ln;
}
