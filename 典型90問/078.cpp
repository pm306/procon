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
    int N, M; cin >> N >> M;
    vector<vector<int>> V(N+1);
    rep(i, M){
        int a, b; cin >> a >> b; if(a>b)swap(a, b);
        V[b].push_back(a);
    }
    int res = 0;
    rept(i, 1, N+1)if(V[i].size()==1)res++;
    cout << res << ln;
}
