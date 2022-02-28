#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
a~bの範囲の値(小数でもいい)から任意個選んでw*1000を作れるか？
作れるなら最小値と最大値を求めよ

「選び方は聞いてない」
選び方が存在する場合、その数は1~1,000,000個(1000グラムのミカン1個で1kg ~ 1グラムのミカン1,000,000個で1000kg)しかない
よって選んだ個数の全探索が可能。(最小値と最大値の全探索、という発想はなかった)
L = 一番小さいミカンをcnt個選んだ時の重さ
R = 一番大きいミカンをcnt個選んだ時の重さ
とし、L<=W<=Rならば何かしらミカンを選ぶ方法がある(みかんの重さは範囲内なら任意なので)
これを全探索すればよい
*/

string NO = "UNSATISFIABLE";

int main(){
    int a, b, w; cin >> a >> b >> w;
    w *= 1000;

    int mi = INF, mx = -1;
    rept(cnt, 1, w+1){
        int L = cnt * a; //一番軽いみかんだけを選ぶ。cnt個選んだときの重さ最小値
        int R = cnt * b; //一番重いみかんだけを選ぶ。cnt個選んだときの重さの最大値
        if(L <= w and w <= R){//wキロになるみかんの選び方が存在する
            chmin(mi, cnt);//
            chmax(mx, cnt);
        }
    }
    if(mi==INF)cout << NO << ln;
    else cout << mi << " " << mx << ln;
}
