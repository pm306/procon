#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 * 2 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
白昼夢
文字列が特定文字列の組み合わせで構成されているかをチェックする。
ただし、前から見ると[dream][dreamer]のどちらで区切れば良いか区別できない。
このような場合は後ろから見ていく。
*/

int main(){
    string s; cin >> s;

    string res = "YES";
    whole(reverse, s);
    int index = 0;
    while(index<s.size()){
        string t1 = s.substr(index, 5), t2 = s.substr(index, 6), t3 = s.substr(index, 7);
        if(t1 == "maerd" or t1 == "esare"){
            index += 5;
        }else if(t2 == "resare"){
            index += 6;
        }else if(t3 == "remaerd"){
            index += 7;
        }else{
            res = "NO";
             break;
        }
    }
    cout << res << ln;
}
