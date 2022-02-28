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

/*
・答えが
  文字列 + (数値)
  と複雑なのでvectorでもたずに都度出力してしまうのが良い
*/

int main(){
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    rep(i, N-1){
        if(A[i+1] == A[i])cout << "stay" << ln;
        else if(A[i+1] > A[i])cout << "up " << A[i+1] - A[i] << ln;
        else cout << "down " << A[i] - A[i+1] << ln;
    }
}
