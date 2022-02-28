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

/*
半分全列挙の典型問題。
半分の全列挙を行い、各値について、最適なペア（今回は最大値）を二分探索で求める。
https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c
*/

int main(){
    int N, M; cin >> N >> M;
    vector<int> P(N);
    rep(i, N){
        cin >> P[i];
    }

    //0~2本の矢を投げて、取りうる値の組み合わせを全列挙する
    vector<int> pattern;
    pattern.push_back(0); //0本投げる
    rep(i, N){
        pattern.push_back(P[i]); //1本投げる
        rep(j, N){
            pattern.push_back(P[i] + P[j]); //2本投げる
        }
    }

    whole(sort, pattern);

    int res = 0;
    for(auto a:pattern){  //半分の矢を使った各パターンについて二分探索で最適解を求める
        if(a > M)break; //前半の2本だけで得点をオーバーしている
        int mx = M - a; //得点できる最大の値
        auto it = whole(lower_bound, pattern, mx);
        it--; //選択可能な最大値。配列に0が含まれるのでpattern.beginは返ってこない
        int score = a + *it;
        chmax(res, score);
    }
    cout << res << ln;
}
