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
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//条件を式変形すると
//Aij + C(i+j) + Ai'j' - C(i'+j')
//となり、左右で独立したマスごとに考えられる(マンハッタン距離の概念が消滅)

//DPで、そのマスより北西側の最低コストを保持する

//式変形により、距離関係の概念を取り去ってマスごとに独立に考えられるようになる
//→DPで一番良い値を選んでいく

int main(){
    int H, W; ll C; cin >> H >> W >> C;
    vector A(H, vector<ll>(W));
    rep(i, H)rep(j, W)cin >> A[i][j];

    ll res = INF;

    rep(_, 2){
        vector D(H, vector<ll>(W, INF)); //D[i][j]:=i,jを南東側のマスとして選んだ時の、相方の最小コスト
        rep(i, H)rep(j, W){
            //自身を除くDPテーブルを更新
            if(i)chmin(D[i][j], D[i-1][j]);
            if(j)chmin(D[i][j], D[i][j-1]);
            chmin(res, A[i][j] + (i+j)*C + D[i][j]);
            chmin(D[i][j], A[i][j] -(i+j)*C); //異なる2マスを選ぶ必要があるので、自身をテーブルに加えるのは更新後
        }

        reverse(all(A));//二次元配列をreverseすると上下が入れ替わる
    }

    cout << res << ln;
}


