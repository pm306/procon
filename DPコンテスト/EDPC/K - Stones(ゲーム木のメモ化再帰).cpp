#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N, K;
int A[101010], win[101010];

int rec(int n){
    if(n == 0) return -1; // 明らかな条件

    if(win[n] != 0)return win[n]; //探索済み

    int ret = -1;
    rep(i, N){
        if(n < A[i])continue;
        if(rec(n-A[i]) == -1)ret = 1;
    }
    return win[n] = ret; //遷移先から1つでも-1を受け取ったら1を返す(最善行動)
}

int main(){
    cin >> N >> K;
    rep(i, N)cin >> A[i];

    if(rec(K) == 1)cout << "First" << ln;
    else cout << "Second" << ln;
}

