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
期待値問題
コインごとに、表になる確率を独立して考え、最後に足し合わせて期待値を求める。
あるコインを見る時、そのコインの約数であるコイン以外は裏表に影響を及ぼさないので無視して考える。
すると、「赤いボール１つと、白いボールＳ個」の置き方の中から、赤いボールの左側に白いボールが偶数個ある確率を求める問題に帰着する。
あとは偶奇分けをして確率を合算していけばよい。
*/

int main(){
    int N; cin >> N;
    vector<int> C(N);
    rep(i, N){
        cin >> C[i];
    }

    double res = 0;
    rep(i, N){
        //約数の数を数える
        int yakusu = 0;
        rep(j, N){
            if(i==j)continue;
            if(C[i] % C[j] == 0)yakusu++;
        }
        if(yakusu % 2 == 0){
            res += (yakusu + 2) / (double)(yakusu * 2 + 2);
        }else{
            res += 0.5;
        }
    }
    cout << fixed << setprecision(12);
    cout << res << ln;
}
