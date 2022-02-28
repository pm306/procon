#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> using V = vector<T>;

/*
良く考えると、各行の高低差？が一定でないと構築できないことに気が付く。
構築できる場合、最も値が小さい行をＢにして、足りない数をＡで補う形にすればOK(A,Bは非負整数しか指定できないため)
*/


int main(){
    int N; cin >> N;
    vector<vector<int>> C(N, vector<int>(N));
    int minId = -1, minNum = INF;
    rep(i, N){
        rep(j, N){
            cin >> C[i][j];
            if(j==0){
                if(chmin(minNum, C[i][j])){
                    minId = i;
                }
            }
        }
    }

    vector<int> sa(N-1);
    rep(i, N-1)sa[i] = C[0][i] - C[0][i+1];
    for(int i=1; i<N; i++){
        rep(j, N-1){
            if(C[i][j]-C[i][j+1] != sa[j]){
                cout << "No" << ln;
                return 0;
            }
        }
    }

    cout << "Yes" << ln;
    rep(i, N){
        cout << C[i][0] - minNum << " ";
    }
    cout << ln;
    rep(i, N){
        cout << C[minId][i] << " ";
    }
    cout << ln;
}
