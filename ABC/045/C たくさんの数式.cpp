#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
再帰全探索
条件がややこしいので注意するタイプ
*/

int main(){
    string s; cin >> s;
    ll res = 0;
    auto dfs = [&](auto&& self, int index, ll sum, ll tmp) -> void{
        if(index == s.size() - 1){
            res += sum + tmp;
            return;
        }
        int nx_num = s[index+1] - '0';
        self(self, index+1, sum + tmp, nx_num); //+
        self(self, index+1, sum, tmp*10 + nx_num); //保持
    };
    dfs(dfs, 0, 0, s[0] - '0');
    cout << res << ln;
}
