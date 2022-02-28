#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
選択肢の少ない順に貪欲、の典型
二次元配列Q[i]:=後ろからi日目(1<=i<=M)に選べるようになる仕事(の報酬額)
これを優先度付きキューに入れて、日ごとに１つ取り出せば良い
*/

ll A[101010], B[101010];
vector<int> Q[101010]; //vectorと普通の配列を両立させている
int main(){
    ll N, M; cin >> N >> M;
    rep(i, N)cin >> A[i] >> B[i];

    rep(i, N)Q[A[i]].push_back(B[i]); //Q日目に選べるアルバイトを後ろから格納
    priority_queue<int> que;
    int res = 0;
    rept(m, 1, M+1){
        for(auto b:Q[m])que.push(b); //選べる仕事を追加
        if(que.size()){
            res += que.top(); que.pop();
        }
    }
    cout << res << ln;
}
