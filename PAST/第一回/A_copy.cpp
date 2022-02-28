#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
https://blog.hamayanhamayan.com/entry/2019/12/31/2350//

・数値を左から取り出す時、10倍する(10進数での1ビットシフトのような感じ) + 次の数値を足す
・foreマクロ
*/

int main(){
    string S; cin >> S;
    int res = 0;
    fore(s, S){
        if('0' <= s and s <= '9') res = res * 10 + s - '0';
        else{
            cout << "error" << ln;
            return 0;
        }
    }
    res *= 2;
    cout << res << ln;
}
