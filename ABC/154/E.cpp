#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

string N; int K;
ll dp[110][2][5]; //i-1桁目までチェック済, 未満フラグ, 0でない数字の出現回数

int main(){
    cin >> N >> K;

    vector<int> n; //nの各桁を数字に変換
    for(auto a: N){
        n.push_back(a-'0');
    }

    dp[0][false][0] = 1; //初期化
    for(int i=0; i<N.size(); i++){
        for(int smaller=0; smaller<2; smaller++){
            for(int k=0; k<=K; k++){ // <=K　であることに注意
                for(int nx=0; nx<=(smaller ? 9 : n[i]); nx++){ //nx <= であることに注意
                    dp[i+1][smaller || nx < n[i]][(nx ? k+1 : k)] += dp[i][smaller][k];
                }
            }
        }
    }
    cout << dp[N.size()][0][K] + dp[N.size()][1][K] << ln;
}

// Tips
// ・DPテーブルは外に出す（初期化が面倒）
// ・各桁の値を数値型に変換する
// ・初期値として、先頭の桁に0を追加したと見做す
// ・samaller = 未満フラグ。わからなかったら解説サイト見ろ
