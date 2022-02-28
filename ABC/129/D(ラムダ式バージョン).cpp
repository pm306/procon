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
ラムダ式を使ってみたが、引数が多すぎてかえって面倒になった
*/

int main(){
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    rep(i, h)cin >> grid[i];

    vector<vector<ll>> counts(h, vector<ll>(w, -1));

    auto record = [&](int id, int cnt, int s, int e, bool tate){
        for(int k=s; k<e; k++){
            if(tate)counts[id][k] += cnt;
            else counts[k][id] += cnt;
        }
    };

    rep(i, h){
        int cnt = 0, bef = -1;
        rep(j, w){
            if(grid[i][j]=='#'){
                record(i, cnt, bef+1, j, true);
                cnt = 0;
                bef = j;
            }else{
                cnt++;
            }
        }
        record(i, cnt, bef+1, w, true);       
    }
    rep(j, w){
        int cnt = 0, bef = -1;
       rep(i, h){
            if(grid[i][j]=='#'){
                record(j, cnt, bef+1, i, false);
                cnt = 0;
                bef = i;
            }else{
                cnt++;
            }
        }
        record(j, cnt, bef+1, h, false);
    }
    ll res = 0;
    rep(i, h){
        chmax(res, *max_element(all(counts[i])));
    }
    cout << res << ln;
}   