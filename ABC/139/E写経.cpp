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

/*
実はグラフで解く系。タスクスケジュールと考えるとわかりやすいかも。
有向閉路がある＝DAGにならないのでどこかで詰まる（よくわからん）
閉路検出、最長パス等、典型で学ぶところが多い。
エンコーディングも地味にわかってない。
*/

vector<vector<int>> G;

int encode(int i, int j){
    if(i<j)swap(i, j);
    return i * (i-1) / 2 + j + 1;
}

int seen[2000000];  
int d[2000000]; 
int dfs(int v, int p){
    if(seen[v]==2) return d[v];
    seen[v] = 1;
    for(auto e:G[v]){
        if(e==p)continue;
        if(seen[e]==1){
            cout << -1 << ln;
            exit(0);
        }
        chmax(d[v], dfs(e, v)+1);
    }
    seen[v] = 2;
    return d[v];
}

int main(){
    int n; cin >> n;
    int num = n*(n-1)/2+1;
    G.resize(num);
    rep(i, n){
        int now = 0;
        rep(j, n-1){
            int a; cin >> a; a--;
            int next = encode(i, a);
            G[now].push_back(next);
            now = next;
        }
    }
    cout << dfs(0, -1) << ln;
}   