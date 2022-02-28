#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
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
190-D by ゆっくり
合計 = 平均 * 長さ(unique)
長さが奇数->平均は整数, 偶数だと整数+0.5  ←確かにそうだが、どうやって着目するのか？
→合計*2:
    長さ、平均共に整数値となり、長さ*平均=合計なので共に合計の約数
    長さが奇数:平均は整数*2, つまり偶数
    長さが偶数:平均はx.5*2=2x+1 つまり奇数
    2Nの約数のうち、奇数*偶数の数を列挙する
*/

int main(){
    ll N; cin >> N; N*= 2;
    ll res = 0;
    for(ll i=1; i*i<N; i++){
        if(N % i == 0 and (i % 2 == 1 or N / i % 2 == 1)){
            res += 2;
        }
    }
    cout << res << ln;
}
