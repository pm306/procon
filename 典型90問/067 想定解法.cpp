#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    string n; int k; cin >> n >> k;

    if(n == "0"){
        cout << 0 << ln;
        return 0;
    }

    while(k--){
        //8 to 10
        ll num = 0, x = 1;
        rrep(i, n.size()){
            num += (n[i]-'0')*x;
            x *= 8;
        }
        //10 to 9
        string m = "";
        while(num){
            char c = ('0' + (num%9));
            if(c == '8')c = '5';
            m += c;
            num /= 9;
        }
        reverse(all(m));
        n = m;
    }
    cout << n << ln;
}
