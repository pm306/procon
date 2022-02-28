#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
区間スケジューリング
N<=20までなら、すべての仕事を（可能なら）するorしないの2パターンで全探索できる。
仕事を構造体として持ち、締切の早い順にソートする。
選ぶ仕事の集合が同じであれば、締切の早い仕事を先行うのが常に最適なため
*/

struct work{
    ll c, d, s;

    bool operator<(const work& right) const {
        if(d <= right.d)return true;
        else return false;
    }
};

int main(){
    int N; cin >> N;
    vector<work> W(N);
    rep(i, N){
        ll d, c, s; cin >> d >> c >> s;
        W[i] = {c, d, s};
    }
    sort(all(W));
    //小課題１、２：全部試す
    ll res = 0;
    auto dfs = [&](auto&& self, int n, int d, ll s) -> void{
        if(n == N){
            chmax(res, s);
            return;
        }
        //n番目の仕事ができる(締切に間に合う)ならする
        if(d+W[n].c <= W[n].d){
            self(self, n+1, d+W[n].c, s+W[n].s);
        }
        //しない
        self(self, n+1, d, s);
    };
    dfs(dfs, 0, 0, 0);
    cout << res << ln;
}
