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

int N;
vector<vector<int>> group;
void dfs(vector<int> v){
    if(size(v) == N){
        group.push_back(v);
        return;
    }
    v.push_back(0);
    dfs(v);
    v.pop_back();
    v.push_back(1);
    dfs(v);
    v.pop_back();
    v.push_back(2);
    dfs(v);
}

int main(){
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N-1){
        rept(j, i+1, N){
            ll a; cin >> a;
            A[i][j] = A[j][i] = a;
        }
    }

    vector<int> v;
    dfs(v);

    ll res = -INF;
    fore(v,group){
        ll score = 0;
        rep(i, N){
            rept(j,i+1, N){
                if(v[i]==v[j])score += A[i][j];
            }
        }
        chmax(res, score);
    }
    cout << res << ln;
}
