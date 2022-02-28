#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//a~zそれぞれ、i文字目以降に出現する最左のインデックス
int leftmost_index[101010][26];
int main(){
    int N, K; string S; cin >> N >> K >> S;

    //step1: テーブルの作成(後ろから作る)
    rep(i, 26)leftmost_index[N][i] = N; //出現しない = N
    for(int i=N-1; i>=0; i--){
        for(int a=0; a<26; a++){
            if(S[i]-'a' == a)leftmost_index[i][a] = i; //出現したら更新
            else leftmost_index[i][a] = leftmost_index[i+1][a]; //出現しなければコピー
        }
    }

    //step2: 解答
    string res = "";
    int curid = 0;
    for(int i=1; i<=K; i++){
        for(int a=0; a<26; a++){ //a~zの順に採用可能か調べる
            int nextid = leftmost_index[curid][a];
            //その文字以降すべて採用したとして、K文字以上なら採用可能
            int maxlen = N - (nextid+1) + i; //i:既に選んだ文字数
            if(maxlen >= K){
                res += (char)('a' + a);
                curid = nextid + 1;
                break;
            }
        }
    }
    cout << res << ln;
}
