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
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n, m; cin >> n >> m;
    vector<int> A(m), B(m); rep(i, m)cin >> A[i] >> B[i], A[i]--, B[i]--;
    int k; cin >> k;
    vector<int> C(k), D(k); rep(i, k)cin >> C[i] >> D[i], C[i]--, D[i]--;

    int res = -1;
    for(int bit=0; bit<(1<<k); bit++){
        int cnt = 0; //達成条件数
        vector<int> sara(n);
        for(int i=0; i<k; i++){
            if(bit & (1<<i)){
                //Cを選択
                sara[C[i]] = true;
            }else{
                sara[D[i]] = true;
            }
        }
        rep(i, m){
            if(sara[A[i]] and sara[B[i]])cnt++;
        }
        chmax(res, cnt);
    }
    cout << res << ln;
}

//////////////////////////////////////////////
//bit全探索。好きだよね……
//ミスりやすいからテンプレ置いとくべきかもしれない。