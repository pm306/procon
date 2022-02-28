#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
O(1)問題。最初題意をはき違えた
H,Wが1のコーナーケースに気を付ける
*/

long long getCeil(ll a, ll b){
    return (a + b - 1) / b;
}

int main(){
    int H, W; cin >> H >> W;
    if(H==1 or W==1)cout << max(H, W) << ln;
    else cout << getCeil(H, 2) * getCeil(W, 2) << ln;
}

