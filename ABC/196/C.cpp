#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
2回繰り返しとなる数字を数え上げる

後ろを固定すると、前も一意に決まる
後ろを昇順に探索して全体を作り、Nより大きくなったらループを抜ける
*/

int main(){
    ll N; cin >> N;
    ll res = 0;
    rept(i, 1, 1234567){
        ll pre = i;
        string s = to_string(i);
        int digits = s.length();
        rep(i, digits)pre *= 10;
        ll x = pre + i;
        if(x > N)break;
        res++;
    }
    cout << res << ln;
}
