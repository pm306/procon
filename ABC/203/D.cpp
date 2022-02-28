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

    int N, K; cin >> N >> K;
    int A[880][880], S[880][880]{};
    rep(i, N)rep(j, N) cin >> A[i][j];

    //K*Kの区画のうち、中央値がval以下であるものが存在するか
    //->区画のうち、その中に含まれるvalより大きい数がfloor(K*K/2)+1個未満であるものは存在するか？
    int lim = (K * K / 2) + 1;
    auto check = [&](int val) -> bool{
        rep(i, N){
            rep(j, N){
                S[i+1][j+1] = S[i+1][j] + S[i][j+1] - S[i][j];
                if(A[i][j] > val)S[i+1][j+1]++;
            }
        }
        rep(i, N-K+1){
            rep(j, N-K+1){
                if(S[i+K][j+K] + S[i][j] - S[i][j+K] - S[i+K][j] < lim)return true;
            }
        }
        return false;
    };

    int ng = -1, ok = INF;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << ok << ln;
}
