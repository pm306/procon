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
単なる再帰全探索なのだが、bit演算に目を取られて気付くのに時間がかかってしまった
制約がN<=20なのでしきりを全部試せる。
演算は仕切りがない間はorで加算していき、仕切りがあるor最後ならxorする、という手法。
*/

int main(){
    int N; cin >> N;
    V<ll> A(N);
    for(auto& a:A)cin >> a;

    ll res = LINF;
    auto dfs = [&](auto&& self, int p, ll tmp, ll val){
        if(p == N-1){
            val ^= tmp;
            chmin(res, val);
            return;
        }
        p++;
        self(self, p, tmp | A[p], val);
        self(self, p, A[p], val ^ tmp);
    };
    dfs(dfs, 0, A[0], 0);
    cout << res << ln;
}
