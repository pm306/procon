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
bitごとの60個の小問として考える。
Ｎが小さく、条件が複雑なので全探索。
*/

using mint = modint1000000007;

int main(){
    int N, Q; cin >> N >> Q;
    vector<ll> X(Q),Y(Q),Z(Q),W(Q);
    rep(i, Q)cin >> X[i] >> Y[i] >> Z[i] >> W[i], X[i]--, Y[i]--, Z[i]--;

    //各bitごとに全パターンを探索し、クエリを確認する
    //mask:=調査してるビットのインデックス
    //bit:=各Aのmask番目のビットが立っているかを「仮定」した値
    mint res = 1;
    for(int mask=0; mask<60; mask++){
        //bit全探索
        mint pat = 0;
        for(int bit=0; bit<1<<N; bit++){
            //全てのビットパターンがQ個のクエリを満たしているか調べる
            bool ok = true;
            for(int i=0; i<Q; i++){
                //x, y, z:=bitにおいてx,y,z番目のbitが立っているかどうか
                int x = bit & 1<<X[i], y = bit & 1<<Y[i], z = bit & 1<<Z[i];
                //ax = ay = az = 0
                if((W[i] & 1LL << mask) == 0){
                    if(x or y or z)ok = false;
                }
                //!(ax = ay = az = 0)
                else{
                    if(!(x or y or z))ok = false;
                }
            }
            pat += ok;
        }
        res *= pat;
    }
    cout << res.val() << ln;
}

