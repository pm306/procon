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
後退解析

↓詳細
https://qiita.com/drken/items/4e1bcf8413af16cb62da#4-%E5%BE%8C%E9%80%80%E8%A7%A3%E6%9E%90-%E3%82%B5%E3%82%A4%E3%82%AF%E3%83%AB%E3%81%AB%E3%82%88%E3%82%8B%E5%BC%95%E3%81%8D%E5%88%86%E3%81%91%E3%81%AE%E3%81%82%E3%82%8B%E3%82%B2%E3%83%BC%E3%83%A0
*/

const int MAX_V = 150000;

int main(){
    int N; cin >> N;
    vector<string> S(N); rep(i, N)cin >> S[i];

    vector<vector<int>> g(MAX_V); //逆向きの有向グラフ
    vector<int> deg(MAX_V); //出次数
    map<string, int> str_id;
    int idx = 1;
    for(auto& s:S){
        string from = s.substr(0, 3), to = s.substr((int)s.size()-3, 3);
        int a, b;
        if(str_id[from]==0){
            str_id[from] = idx;
            a = idx++;
        }else{
            a = str_id[from];
        }
        if(str_id[to]==0){
            str_id[to] = idx;
            b = idx++;
        }else{
            b = str_id[to];
        }
        g[b].push_back(a);
        deg[a]++;
    }

    //後退解析
    vector<int> dp(MAX_V, -1);
    queue<int> que;
    rept(i,1, MAX_V){
        if(deg[i]==0){
            dp[i] = 0; //lose
            que.push(i);
        }
    }

    while(que.size()){
        int v = que.front(); que.pop();
        fore(nv, g[v]){
            if(dp[nv] != -1)continue; //探索済み
            deg[nv]--;

            if(dp[v]==0){
                dp[nv] = 1; //win
                que.push(nv);
            }

            else if(dp[v]==1){
                if(deg[nv]==0){
                    dp[nv] = 0; //lose
                    que.push(nv);
                }
            }
        }
    }

    //query
    vector<string> ans;
    fore(s,S){
        int v = str_id[s.substr(s.size()-3, 3)];
        if(dp[v] == 1)ans.push_back("Aoki");
        else if(dp[v]== 0)ans.push_back("Takahashi");
        else if(dp[v] == -1)ans.push_back("Draw");
    }

    fore(a,ans)cout << a << ln;
}

