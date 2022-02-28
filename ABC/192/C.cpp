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
実装問題

数値→文字列→数値 の変換
*/

int main(){
    int N, K; cin >> N >> K;

    auto g1 = [](int n) -> int{
        string s = to_string(n);
        sort(all(s), greater<int>());
        int res = 0;
        rep(i, s.size()){
            res = res * 10 + (s[i] - '0');
        }
        return res;
    };
    auto g2 = [](int n) -> int{
        string s = to_string(n);
        sort(all(s));
        int res = 0; bool not_zero = false;
        rep(i, s.size()){
            if(!not_zero and s[i] == '0')continue;
            not_zero = true;
            res = res * 10 + (s[i] - '0');
        }
        return res;
    };
    auto f = [&](int n) -> int{
        return g1(n) - g2(n);
    };
    int res = N;
    rep(i, K){
        res = f(res);
    }
    cout << res << ln;
}
