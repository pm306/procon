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


int main(){
    int N; cin >> N;
    string S; cin >> S;

    string T = "";
    int red = count(all(S), 'R'), white = count(all(S), 'W');
    rep(i, red)T += "R";
    rep(i, white)T += "W";

    int res = 0;
    rep(i, N)if(S[i]!=T[i])res++;
    cout << res / 2 << ln;
}
