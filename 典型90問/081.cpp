#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
区間カウント = 累積和, という思考を身に着ける
[0,0,1,3,2,3,1,0,1,1]みたいに属する数をプロットして区間和を取得すれば良い
ABC203-Dも同様

一定区間に属しているオブジェクトの数を高速に知りたい時はプロット→累積和
二次元でも同様

*/

ll A[5010][5010], S[5010][5010]; //A[i][j] := 身長i,体重jの生徒の人数
int main(){
    int N, K; cin >> N >> K;
    rep(i, N){
        int a, b; cin >> a >> b;
        A[a][b]++;
    }

    rep(i, 5001){
        rep(j, 5001){
            S[i+1][j+1] = S[i+1][j] + S[i][j+1] - S[i][j] + A[i][j];
        }
    }
    ll res = 0;
    //[a-a+k][b-b+k]
    for(int a=1; a+K<=5000; a++){
        for(int c=1; c+K<=5000; c++){
            int b=a+K+1, d=c+K+1;
            chmax(res, S[b][d] - S[b][c] - S[a][d] + S[a][c]);
        }
    }
    cout << res << ln;
}

