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

//初項a, 公差d, 項数nの等差数列の和
ll sumTousa(ll n, ll a=1, ll d=1){
    return (2 * a + (n - 1) * d) * n / 2;
}

/*
構築問題。
等差数列の和を求める関数を作った。
公式解説が丁寧。条件のうちいくつかを撤廃して考えてから、条件を付加していくと良いらしい。
この場合、総和が０である、を一旦除外して考えると「１箇所を変更すれば済む」という事実に気付く。
*/

int main(){
    int A, B; cin >> A >> B;

    vector<int> ans;
    if(A >= B){
        for(int i=1; i<=A; i++){
            ans.push_back(i);
        }
        for(int i=1; i<=B-1; i++){
            ans.push_back(-i);
        }
        ans.push_back(-sumTousa(A-B+1, B));
    }
    else if(B > A){
        for(int i=1; i<=B; i++){
            ans.push_back(-i);
        }
        for(int i=1; i<=A-1; i++){
            ans.push_back(i);
        }
        ans.push_back(sumTousa(B-A+1, A));
    }

    for(auto a: ans)cout << a << " ";
    cout << ln;
}
