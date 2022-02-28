#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void add(ll &a, ll b){a += b; if(a>=LINF)a = LINF;} //構築パターンは64ビット整数に収まらない場合があるが、本問では1e18個数えれば十分なので圧縮する

ll dp[1000010][26];
int main(){
    string S; ll K; cin >> S >> K;
    int n = S.size();

    //DP
    dp[n-1][S[n-1] - 'a'] = 1;
    rrep(i, n-2){
        rep(j, 26){
            //i番目の文字がjではない
            if(j != (int)(S[i] - 'a')){
                add(dp[i][j], dp[i+1][j]);
            }
            else{
                add(dp[i][j], 1); //ｊを採用した後は何も採用しない
                rep(k, 26){//次にa~zを採用する
                    add(dp[i][j], dp[i+1][k]);
                }
            }
        }
    }

    //復元
    ll sum = 0;
    rep(i, 26)add(sum, dp[0][i]);

    //部分文字列の個数がK個未満
    if(sum < K){
        cout << "Eel" << ln;
    }
    else{
        string res = "";
        rep(i, n){
            //次の文字を決める
            int j;
            for(j=0; j<26; j++){
                if(K - dp[i][j] <= 0)break;
                K -= dp[i][j];
            }
            char c = 'a' + j; //次の文字はc
            res += c;
            K--; //cを取って終了し、残りは何も取らない
            if(K <= 0)break; //cを取って終了する
            //続行する
            while(S[i]!=c)i++;
        }
        cout << res << ln;
    }
}

