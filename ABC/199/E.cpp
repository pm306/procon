#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
巡回セールスマン問題の亜種
「訪問済みの地点」を「見たインデックス」に置き換えると分かりやすい。
判定のため、ビット演算で集合を復元して調査している。
*/

int main(){
    int N, M; cin >> N >> M;
    vector<int> X(M), Y(M), Z(M);
    rep(i, M){
        cin >> X[i] >> Y[i] >> Z[i];
    }

    ll dp[1<<18]{}; dp[0] = 1;
    for(int bit=0; bit<(1<<N); bit++){
        vector<int> S; //集合
        for(int i=0; i<N; i++){
            if((bit>>i)&1){
                S.push_back(i+1);
            }
        }
        for(int i=0; i<N; i++){
            if((bit>>i)&1)continue; //既に存在する
            S.push_back(i+1);
            bool fg = true;
            rep(j, M){
                if(X[j]!=S.size())continue; //丁度になったら数えれば良い
                int cnt = 0;
                for(auto s:S){
                    if(s<=Y[j])cnt++;
                }
                if(cnt>Z[j]){
                    fg = false;
                }
            }
            if(fg)dp[bit+(1<<i)] += dp[bit];
            S.pop_back();
        }
    }
    cout << dp[(1<<N)-1] << ln;
}
