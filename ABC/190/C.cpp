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

/*
Kが小さいので再帰全探索

bit全探索嫌いなのでこっちで済ませたい。
*/

int main(){
    int N, M; cin >> N >> M;
    vector<ll> A(M), B(M); rep(i, M)cin >> A[i] >> B[i], A[i]--, B[i]--;
    int K; cin >> K;
    vector<ll> C(K), D(K); rep(i, K)cin >> C[i] >> D[i], C[i]--, D[i]--;

    auto dfs = [&](auto&& self, int n, vector<int> ball) -> int{
        if(n == K){
            int res = 0;
            rep(i, M){
                if(ball[A[i]] and ball[B[i]])res++;
            }
            return res;
        }

        int res = 0;
        ball[C[n]]++;
        chmax(res, self(self, n+1, ball));
        ball[C[n]]--;
        ball[D[n]]++;
        chmax(res, self(self, n+1, ball));
        return res;
    };
    vector<int> ball(N);
    cout << dfs(dfs, 0, ball) << ln;
}
