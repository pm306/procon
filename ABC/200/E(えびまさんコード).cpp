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
#define repr(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
えびまさんの解法
3次元の場合の数を立方体に落とし込んで図形的に考える。すげー
*/

ll tri(ll n){
    return n * (n + 1) / 2;
}

int main(){
    ll N, K; cin >> N >> K;
    for(int s=0; s<=3*(N-1); s++){
        ll cnt; //sum=sのときの場合の数
        if(s <= N-1){
            cnt = tri(s+1); //総和の公式 s=nのとき、場合の数はsouwa(s+1) https://twitter.com/evima0/status/1391038129025392647 を見るとわかりやすいよ
        }
        else if(s <= 2 * (N - 1)){
            //正方形から左下と右上を引いている
            //(s-N)+1:左下、(2N-s-3+1):右上 右上の始点？ = 2N - sで求まる(z=0としたとき、立方体の右上１パターンのみになるのは2N)
            cnt = N * N - tri(s - N + 1) - tri(2 * N - s - 2);
        }
        else{
            cnt = tri(3 * N - 2 - s); //パターン1と同じことを右上からやってる。t = MAX(s) - (x+y+z) として tri(t+1)。対称性？
        }
        //K番目の組み合わせがsum(cnt)である時
        if(K <= cnt){
            //xを決定する。x~0<Nで走査
            rep(x, N){
                ll c;//xを決めた時の軸の個数
                //左下から隙間なく構築される
                if(s <= N - 1){
                    c = max(0, s + 1 - x);
                }
                //左下と右上に隙間ができる
                else if(s <= 2 * (N - 1)){
                    c = N - abs(x - (s - N + 1));
                }
                //右上から隙間なく構築される
                else{
                    c = max(0LL, 2 * N - 1 - s + x);
                }
                //K番目の値がx列目にあるとき、xが決定するのでyを走査する。1回しか走査しないのでO(N)
                if(K <= c){
                    rep(y, N){
                        //条件1: x+yがsum-n未満だと、zがnより大きくなるので不適
                        //条件2: x+yがsより大きいと「(x,y,z)<N」の条件を満たさないので不適
                        if(x + y >= s - (N - 1) and x + y <= s){
                            if(K == 1){//求めるべき答え
                                cout << x+1 << " " << y+1 << " " << s-x-y+1 << ln;
                                return 0;
                            }
                            K--; //x軸で切り取られてるので1引くだけでいい
                        }
                    }
                }
                //なければ場合の数を引く
                K -= c;
            }
        }
        K -= cnt; //sum(cnt)でなければsum(snt):パターン数を引く
    }
}
