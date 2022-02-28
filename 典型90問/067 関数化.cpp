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

//10進数->n進数の置換
string base_10_to_n(ll X, int n){
    if(X/n)return base_10_to_n(X/n, n) + to_string(X%n);
    return to_string(X%n);
}

//n進数->10進数の置換
ll base_n_to_10(string s, int n){
    const string number = "0123456789ABCDEF";

    ll ret = 0, x = 1;
    for(int i=s.size()-1; i>=0; i--){
        ret += number.find(s[i]) * x;
        x *= n;
    }
    return ret;
}

//文字列中のxをyに置き換える
void str_replace(string &s, char x, char y){
    for(auto &c: s)if(c == x)c = y;
}

int main(){
    string N; int K; cin >> N >> K;

    while(K--){
        ll tmp = base_n_to_10(N, 8);
        N = base_10_to_n(tmp, 9);
        str_replace(N, '8', '5');
    }
    cout << N << ln;
}
