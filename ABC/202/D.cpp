#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
using vll = vector<long long>;
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
辞書順k番目の文字列を作る
例によって前から貪欲に見る。

i文字目がaである場合の組み合わせは、
i+1~A+B文字の文字数をn、使えるaの数をrとするとnCr通り。
*/

ll nCr(ll n, ll r){
    if(n==0 or r==0)return 1;
    ll res = 1, a = n, b = 1;
    rep(i, r){res *= a; res /= b; a--; b++;}
    return res;
}

int main(){
    ll A, B, K; cin >> A >> B >> K;

    string res = "";
    int keta = A+B;
    rep(i, keta){
        ll com = nCr(A-1+B, B);
        if(A == 0 or K > com){
            res += "b";
            K -= com;
            B--;
        }else{
            res += "a";
            A--;
        }
    }
    cout << res << ln;
}

