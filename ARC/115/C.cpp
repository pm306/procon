#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> using V = vector<T>;

/*
構築問題
各数の約数に割り当てられている数を見てそれ+１の数を当てはめてけば良い
約数は100個もないので全列挙してから空いている最小の数を探しても間に合う

最初ふるい的な感じでチェックいれてたら間違えた
*/

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int N; cin >> N;

    V<int> ans(N+10);
    for(int i=1; i<=N; i++){
        auto ed = enum_divisors(i);//約数を取得
        V<int> check(100);//約数は100もないので、割り当てる数は100未満で足りる
        for(auto a:ed){//各約数について、使われている最小値をtrueとする
            check[ans[a]] = true;
        }
        for(int j=1; j<100; j++){
            if(check[j]==false){//約数に割り当てられていない最小値を採用
                ans[i] = j;
                break;
            }
        }
    }

    for(int i=1; i<=N; i++)cout << ans[i] << " ";
    cout << ln;
}
