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
過去の自分よ見てるか！？
ビット全探索のが楽だろこれ
*/

int main(){
    int N, M; cin >> N >> M;
    vector<ll> A(M), B(M); rep(i, M)cin >> A[i] >> B[i], A[i]--, B[i]--;
    int K; cin >> K;
    vector<ll> C(K), D(K); rep(i, K)cin >> C[i] >> D[i], C[i]--, D[i]--;

    int res = 0;
    for(int mask=0; mask<1<<K; mask++){
        vector<int> sara(N);
        //put ball
        rep(i, K)if(mask>>i&1)sara[C[i]] = true;
        else sara[D[i]] = true;
        //judge
        int cnt = 0;
        rep(i, M){
            if(sara[A[i]] and sara[B[i]])cnt++;
        }
        chmax(res, cnt);
    }
    cout << res << ln;
}
