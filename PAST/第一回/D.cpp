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
特になし
*/

int A[202020];
int main(){
    int N; cin >> N;
    rep(i, N){
        int a; cin >> a;
        A[a]++;
    }
    int plus = -1, minus = -1;
    rept(i, 1, N+1){
        if(A[i]==2)plus = i;
        if(A[i]==0)minus = i;
    }
    if(plus==-1)cout << "Correct" << ln;
    else cout << plus << " " << minus << ln;
}
