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
明かりを照らす系の問題。
最近類題で間違えたので凹んでいる。
最初は４回にぶたんしようとした（本番でも同じことやった）がめんどくさすぎるのでやめようね！！！！
縦、横ごとに照らされるマスの数を数えれば良い。
この手のカウンタは末尾処理？を忘れがちなので注意されたし
*/

int main(){
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    rep(i, h)cin >> grid[i];
 
    vector<vector<ll>> counts(h, vector<ll>(w, -1));
    rep(i, h){
        int cnt = 0, bef = -1;
        rep(j, w){
            if(grid[i][j]=='#'){
                for(int k=bef+1; k<j; k++){
                    counts[i][k] += cnt;
                }
                cnt = 0;
                bef = j;
            }else{
                cnt++;
            }
        }
        for(int k=bef+1; k<w; k++){
            counts[i][k] += cnt;
        }        
    }
    rep(j, w){
        int cnt = 0, bef = -1;
       rep(i, h){
            if(grid[i][j]=='#'){
                for(int k=bef+1; k<i; k++){
                    counts[k][j] += cnt;
                }
                cnt = 0;
                bef = i;
            }else{
                cnt++;
            }
        }
        for(int k=bef+1; k<h; k++){
            counts[k][j] += cnt;
        }
    }
    ll res = 0;
    rep(i, h){
        chmax(res, *max_element(all(counts[i])));
    }
    cout << res << ln;
}   