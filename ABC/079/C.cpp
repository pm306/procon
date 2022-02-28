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
char型の連結は数値型に化けるので注意されたし
*/

int main(){
    string s; cin >> s;
    string res = "";
    auto dfs = [&](auto&& self, int index, int sum, vector<string> op){
        if(index == 3){
            if(sum==7){
                res = s[0] + op[0] + s[1] + op[1] + s[2] + op[2] + s[3] + "=7";
            }
            return;
        }
        index++;
        int nx_num = s[index] - '0';
        op.push_back("+");
        self(self, index, sum+nx_num, op);
        op.pop_back();
        op.push_back("-");
        self(self, index, sum-nx_num, op);
    };
    vector<string> op;
    dfs(dfs, 0, s[0] - '0', op);
    cout << res << ln;
}
