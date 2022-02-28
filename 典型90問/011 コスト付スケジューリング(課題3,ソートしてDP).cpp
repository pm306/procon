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

/*
区間スケジューリング + ナップザック
ソートしてDPするタイプの問題
*/

struct work{
    ll c, d, s;

    bool operator<(const work& right) const {
        if(d <= right.d)return true;
        else return false;
    }
};

ll dp[5010][5010];
int main(){
    ll N; cin >> N;
    vector<work> W(N);
    rep(i, N){
        ll d, c, s; cin >> d >> c >> s;
        W[i] = {c, d, s};
    }
    sort(all(W));

    rep(i, N){
        rep(j, 5001){
            chmax(dp[i+1][j], dp[i][j]);
            if(j >= W[i].c and j <= W[i].d){
                chmax(dp[i+1][j], dp[i][j-W[i].c] + W[i].s);
            }
        }
    }
    cout << *max_element(dp[N], dp[N]+5010) << ln;
}
