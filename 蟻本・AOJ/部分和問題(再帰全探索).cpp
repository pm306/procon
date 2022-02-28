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

int main(){
    int N, K; cin >> N >> K;
    int A[20]; rep(i, N)cin >> A[i];

    auto dfs = [&](auto&& self, int i, int sum) -> bool{
        if(i == N) return sum == K;

        //a[i]を使わない
        if(self(self, i+1, sum))return true;
        //a[i]を使う
        if(self(self, i+1, sum+A[i]))return true;

        //a[i]を使う、使わない、のいずれもKが作れないのでfalseを返す
        return false;
    };

    cout << (dfs(dfs, 0, 0) ? "Yes" : "No") << ln;
}

