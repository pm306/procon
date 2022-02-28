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
キーポイント
・条件を満たすパターンのみを全列挙
・dfsでマスを埋めていく。全列挙でも間に合うが、同じ盤面を2回探索しないよう注意
・連結になるように＠を埋める

*/

using pll = pair<ll, ll>;

set<vector<string>> used; //調査済みの盤面
vector<string> s; //現在の盤面
ll res = 0, N, K;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,-1,1};

bool valid(ll x, ll y){ //(x,y)が盤面に含まれているかどうか
    return 0 <= x and x < N and 0 <= y and y < N;
}

void dfs(ll num){
    //num:=あと何マス赤マスを置くか

    if(used.find(s) != used.end()){
        return; //調査済みの盤面
    }
    used.insert(s);

    if(num == 0){//赤マスをK個塗り終えた時。答えに１を加えて探索を打ち切る。
        res++;
        return;
    }

    vector<pll> next; //次に赤マスを塗る候補
    rep(i, N){
        rep(j, N){
            //(i, j)を赤マスにできる条件は
            //s[i][j] == '.' and s[i][j]の隣に赤マスがある
            if(s[i][j] == '.'){
                bool fg = false;
                rep(k, 4){
                    int ny = i+dy[k], nx = j+dx[k];
                    if(valid(ny, nx) and s[ny][nx] == '@')fg = true;
                }
                if(fg)next.emplace_back(i, j);//次に赤マスを塗る候補にi,jを追加
            }
        }
    }

    for(auto [y, x]:next){
        s[y][x] = '@';
        dfs(num-1);
        s[y][x] = '.';
    }
}

int main(){
    cin >> N >> K;
    s.resize(N);
    rep(i, N)cin >> s[i];

    rep(i, N){
        rep(j, N){
            if(s[i][j]=='.'){
                s[i][j] = '@';
                dfs(K-1);
                s[i][j] = '.';
            }
        }
    }
    cout << res << ln;
}
