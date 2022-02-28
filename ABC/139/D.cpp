#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
「選択肢の少ない（後ろから）貪欲」問題

N = 5 の場合を考える
i = 1 のとき、どのpを当てはめてもmax=0
i = 2 のとき、p=1,3,5のときmax=1
i = 3 のとき、p=2,5のときmax=2
i = 4 のとき  p=3のときmax=3
i = 5 のとき　p=4のときmax=4

ということで、i=2~Nについて、i-1を割り当ていくことによって常に最大のmodを得ることができる
*/

ll getSouwa(ll n){
    return n * (n+1) / 2;
}

int main(){
    ll N; cin >> N;
    cout << getSouwa(N-1) << ln;
}
