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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
・文字列中の文字がアルファベットか数字が判定する
・文字列を数値に変換する
*/

int main(){
    string S; cin >> S;
    for(auto& s:S)if(s>='a' and s<='z'){
        cout << "error" << ln;
        return 0;
    }
    cout << stoi(S) * 2 << ln;
}
