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
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
「下界」を考える、考察重視の問題
解説が神なのでたまに読むと良いかも

まず、0の数が一致していない場合は成立しない
一致している場合を考える
※自分の解法は、左詰めと右詰めを両方試して少ない方を採用、というもの
※実際は、tの0ごとに左詰めと右詰めの良い方を選択すると、各0につき1回の操作で達成できる
なんとなく頭にうかんでいたが、「左右貪欲」で考察が止まってしまった

S,Tのゼロの位置をまとめる
Sにおけるi個のゼロはTにおけるi個目のゼロと一致するのが最善(他のゼロをまたげないので)
→zeroS[i] != zeroT[i] の個数　という仮説が導けるかも
手を動かすと、順当に動かしても他のゼロが邪魔で、どう動かせば最小なのかわかりづらい

zeroS[i] < zeroT[i] しかない不一致リストの場合(Ｓのゼロが全部左に寄っている)
iの大きい順に右に動かせばいいだけ
zeroS[i] > zeroT[i] がある場合
一見厄介。しかし、条件を満たすiのうち最小のものを左に詰めることで、1手で一致させられる
以上により、すべての不一致iについて1手で一致させられ、1手で1つしか一致させられないことになる
*/

int main(){
    int N; string S, T; cin >> N >> S >> T;

    if(count(all(S), '0') != count(all(T), '0')){
        cout << -1 << ln;
        return 0;
    }

    vector<int> A, B;
    rep(i, N){
        if(S[i]=='0')A.push_back(i);
        if(T[i]=='0')B.push_back(i);
    }
    int res = 0;
    rep(i, A.size()){
        if(A[i] != B[i])res++;
    }
    cout << res << ln;
}
