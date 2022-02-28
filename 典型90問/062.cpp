#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using graph = vector<vector<int>>;

int main(){
    int N; cin >> N;
    graph G(N);
    vector<int> seen(N), ans;
    queue<int> que;

    rep(i, N){
        int a, b; cin >> a >> b; a--, b--;
        if(a==i or b==i){que.push(i); seen[i] = true;}
        G[a].push_back(i);
        G[b].push_back(i);
    }

    while(que.size()){
        int v = que.front(); que.pop();
        ans.push_back(v);
        for(auto& e:G[v]){
            if(!seen[e]){
                seen[e] = true;
                que.push(e);
            }
        }
    }
    if(ans.size()<N)cout << -1 << ln;
    else{
        for(int i=N-1; i>=0; i--)cout << ans[i] + 1 << ln;
    }
}

