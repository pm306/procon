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
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N, W, A[20];
bool rec(int i, int w){
    //ベースケース
    if(i == 0)return w == 0;

    //A[i-1]を選ばない
    if(rec(i-1, w))return true;
    //A[i-1]を選ぶ
    if(rec(i-1, w-A[i-1]))return true;

    return false;
}

int main(){
    cin >> N >> W;
    rep(i, N)cin >> A[i];

    cout << (rec(N, W) ? "Yes" : "No") << ln;
}

