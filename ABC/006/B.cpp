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
メモ化再帰テンプレ
*/

int main(){
    int N; cin >> N;
    vector<int> memo(1e6+10);
    auto dfs = [&](auto&& self, int num){
        if(num==1 or num==2)return 0;
        if(num==3)return 1;
        if(memo[num]!=0)return memo[num];
        return memo[num] = (self(self,num-1) + self(self, num-2) + self(self, num-3)) % 10007;
    };
    cout << dfs(dfs, N) << ln;
}
