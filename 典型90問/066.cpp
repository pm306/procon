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

/*
各Ajについて、Aiをそれぞれ独立に計算して問題ない。
Aiは他の値に寄らず、独立に値を決めるので
*/


int L[110], R[110];
int main(){
    int N; cin >> N;
    rep(i, N)cin >> L[i] >> R[i];

    double res = 0;
    for(int j=1; j<N; j++){
        for(int i=0; i<j; i++){
            //ai > aj である確率を数え上げる
            int num_i = R[i]-L[i]+1, num_j = R[j]-L[j]+1;
            int cnt = 0;
            for(int a=L[i]; a<=R[i]; a++){
                for(int b=L[j]; b<=R[j]; b++){
                    if(a > b)cnt++;
                }
            }
            res += (double)cnt / (num_i * num_j);
        }
    }
    cout << fixed << setprecision(12);
    cout << res << ln;
}

