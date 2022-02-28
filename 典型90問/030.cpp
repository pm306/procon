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
素因数の数を数える
調和級数
*/


int soinsu[10101010];
int main(){
    int N, K; cin >> N >> K;
    for(int i=2; i<=N; i++){
        if(soinsu[i]>=1)continue;
        for(int j=i; j<=N; j+=i){
            soinsu[j]++;
        }
    }

    ll res = 0;
    for(int i=2; i<=N; i++){
        if(soinsu[i] >= K)res++;
    }
    cout << res << ln;
}
