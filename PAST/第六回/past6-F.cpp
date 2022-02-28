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



int main(){
    int N, L, T, X; cin >> N >> L >> T >> X;
    vector<int> A(N), B(N);
    rep(i, N)cin >> A[i] >> B[i];

    int timer = 0, overtime = 0;
    for(int i=0; i<N; ){
        if(A[i] > T and B[i] >= L){
            cout << "forever" << ln;
            return 0;
        }
        if(B[i] >= L and overtime + A[i] >= T){
            timer += T - overtime + X;
            if(overtime + A[i] == T)i++;
            overtime = 0;
        }
        else{
            timer += A[i];
            if(B[i] >= L)overtime += A[i];
            else overtime = 0;
            i++;
        }
    }
    cout << timer << ln;
}
