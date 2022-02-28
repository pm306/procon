#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
modの取り方は200種類しかないので探索を途中で打ち切っても大丈夫
2^8=256なので10個見ればOK
*/


int main(){
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }

    vector<vector<int>> pat(200); //modごとの取り方
    vector<int> B, C;
    auto dfs = [&](auto&& self,int idx, ll num, vector<int> v) -> void{
        if(idx == min(10, N))return;

        int nx = (num+A[idx])%200;
        v.push_back(idx);
        if(pat[nx].size() == 0){
            pat[nx] = v;
        }else{
            bool fg = false;
            if(pat[nx].size() == v.size()){
                rep(i, v.size()){
                    if(A[pat[nx][i]] != A[v[i]])fg = true;
                }
            }else fg = true;
            if(fg){
                B = pat[nx];
                C = v;
            }
        }
        self(self, idx+1, nx, v);
        v.pop_back();
        self(self, idx+1, num, v);
    };
    vector<int> v;
    dfs(dfs, 0, 0, v);
    if(B.size()){
        cout << "Yes" << ln;
        cout << B.size() << " ";
        for(auto b:B)cout << b+1 << " "; cout << ln;
        cout << C.size() << " ";
        for(auto c:C)cout << c+1 << " "; cout << ln;
    }
    else{
        cout << "No" << ln;
    }
}
