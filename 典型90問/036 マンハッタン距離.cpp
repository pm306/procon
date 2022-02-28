#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
マンハッタン距離 -> 45度回転
図を見るとわかりやすい
https://github.com/E869120/kyopro_educational_90/blob/main/editorial/036.jpg

45度回転するとマンハッタン距離はmax(|x1-x2|, |y1-y2|)になる。
*/

void rotate_45(ll& X , ll& Y){
    ll x = X, y = Y;
    X -= y;
    Y += x;
}

int main(){
    ll N, Q; cin >> N >> Q;
    vector<ll> X(N), Y(N);
    rep(i, N)cin >> X[i] >> Y[i];

    //step 1 45 rotate
    ll minX = LINF, minY = LINF, maxX = -LINF, maxY = -LINF;
    rep(i, N){
        rotate_45(X[i], Y[i]);
        chmin(minX, X[i]);
        chmax(maxX, X[i]);
        chmin(minY, Y[i]);
        chmax(maxY, Y[i]);
    }

    //step 2 query
    while(Q--){
        int q; cin >> q; q--;
        ll res = max({abs(X[q]-minX), abs(X[q]-maxX), abs(Y[q]-minY), abs(Y[q]-maxY)});
        cout << res << ln;
    }
}
