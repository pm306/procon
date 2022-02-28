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

//0~nで4と9を含まない個数
ll func(ll n){
    string s = to_string(n);
    int len = s.size();
    ll dp[len+1][2]{};
    dp[0][0] = 1;
    for(int i=0; i<len; i++){
        ll k = 0;
        for(int j=0; j<9; j++){
            if(j==4)continue;
            if(j<s[i]-'0')k++;
        }

        if(s[i] == '4' || s[i] == '9'){
            dp[i+1][0] = 0;
        }else{
            dp[i+1][0] = dp[i][0];
        }
        dp[i+1][1] = k * dp[i][0] + 8 * dp[i][1];
    }
    return dp[len][0] + dp[len][1];
}

int main(){
    ll A, B; cin >> A >> B;
    ll res = B - A + 1 - (func(B) - func(A-1));
    cout << res << ln;
}
