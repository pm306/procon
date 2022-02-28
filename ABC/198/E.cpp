#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];//頂点の色
    }

    vector<vector<ll>> G(N);
    rep(i, N-1){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> ans;
    auto dfs = [&](auto&& self, int v, int p, vector<int>& C)->void{
        if(C[A[v]] == 0){
            ans.push_back(v+1);
        }
        C[A[v]]++;
        for(auto e:G[v]){
            if(e==p)continue;
            self(self, e, v, C);
        }
        C[A[v]]--;
    };

    vector<int> C(1e5+10);
    dfs(dfs, 0, -1, C);
    whole(sort, ans);
    for(auto a:ans)cout << a << ln;
}

