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
・隣接行列
・実装がきつい
・t==3 逐次更新するとバグる
・t==3 フォロイーのフォロイーが自分(相互フォロー)だと問題文の条件に反する

フォロイーの集合を示す
a = {b,c}
b = {d}
c = {e}
d = {f}

aのフォロイーのフォロイーをフォローする、とする
本来追加するべき人は{b,e}だが
逐次更新すると
１：bのフォロイーを見た時点でaのフォロイーにdが追加される
２：aがdをフォローしている、ということになるのでdのフォロイーであるfもフォローされる
ということになる

要点
配列Aの情報をもとに配列Aを更新する場合は、更新先の情報は別個に持たないと矛盾する
類題：ABC203-White Pawn(一次元配列から新しい一次元配列の情報を作り出してdpする)
*/

int main(){
    int N, Q; cin >> N >> Q;
    vector<vector<char>> A(N, vector<char>(N, 'N'));

    while(Q--){
        int t; cin >> t;
        if(t==1){
            int a, b; cin >> a >> b; a--, b--;
            A[a][b] = 'Y';
        }
        else if(t==2){
            int a; cin >> a; a--;
            for(int from=0; from<N; from++){
                if(A[from][a] == 'Y')A[a][from] = 'Y';
            }
        }
        else{
            int a; cin >> a; a--;
            vector<int> F; //更新した情報を使って更に更新しないように！
            for(int to=0; to<N; to++){
                if(A[a][to] == 'Y'){
                    for(int tt=0; tt<N; tt++){
                        if(A[to][tt] == 'Y')F.push_back(tt);
                    }
                }
            }
            fore(f,F)A[a][f] = 'Y';
        }
    }
    rep(i, N)A[i][i] = 'N';

    rep(i, N){
        rep(j, N)cout << A[i][j];
        cout << ln;
    }
}
