#include <bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    ll N, K; cin >> N >> K;
    vector<ll> P(N), C(N);
    rep(i, N)cin >> P[i], P[i]--;
    rep(i, N)cin >> C[i];

    ll res = - LINF;
    //startを全探索
    rep(start, N){
        int pos = start;
        vector<ll> score;
        while(true){
            pos = P[pos];
            score.push_back(C[pos]);
            if(pos == start)break;
        }
        ll sum = 0, mx = -LINF;
        for(int i=0; i<min(K,(ll)score.size()); i++){
            sum += score[i];
            chmax(mx, sum);
        }
        if(K < score.size()){
            chmax(res, mx);
        }
        //1周するとマイナス
        else if(sum <= 0){
            chmax(res, mx);
        }
        //1周するとプラス
        else{
            ll m = K / score.size() - 1; //0以上
            ll tmp = sum * (m);
            sum = 0, mx = 0;
            for(int i=0; i<K%score.size()+score.size(); i++){
                sum += score[i%score.size()];
                chmax(mx, sum);
            }
            tmp += mx;
            chmax(res, tmp);
        }
    }
    cout << res << ln;
}
