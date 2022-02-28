#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
角度系。
まだよく理解していない。

Bを固定することで残りの点の偏角が求められるので、Aを全探索して最適なCをにぶたんする。
左右にぶたんのインデックスを求める式が参考になる。
*/

//座標
struct Point{
    double px, py;
};
//構造体の演算
//座標の差を返す
Point operator -(const Point& a1, const Point& a2){
    return Point{a1.px - a2.px, a1.py - a2.py};
}

//座標Gの偏角を求める
double getangle(Point G){
    if(G.py >= 0.0){
        double I = G.px / sqrt(G.px * G.px + G.py * G.py);
        double kaku = acos(I)* 180.0 / M_PI;
        return kaku;
    }else{
        double I = G.px / sqrt(G.px * G.px + G.py * G.py);
        double kaku = acos(I)* 180.0 / M_PI;
        return 360.0 - kaku;
    }
}

//偏角I1 - 原点 - 偏角I2 のなす角度を求める
double getangle2(double I1, double I2){
    double res = abs(I1 - I2);
    if(res >= 180.0)return 360.0 - res;
    return res;
}

int main(){
    int N; cin >> N;
    vector<Point> G(N);
    rep(i, N){
        cin>> G[i].px >> G[i].py;
    }

    double res = 0;
    //点Bを全探索
    rep(i, N){
        //偏角の昇順にソートする
        vector<double> vec;
        rep(j, N){
            if(i==j)continue;
            Point SA = G[j] - G[i]; //座標ずらし
            double angle = getangle(SA); //偏角を取得
            vec.push_back(angle);
        }
        sort(all(vec));

        //点Aを全探索して、最も偏角の大きくなる点Cを二分探索で求める
        for(auto v: vec){
            double target = v + 180.0;
            if(target >= 360.0)target -= 360.0;
            int pos1 = lower_bound(all(vec), target) - vec.begin();

            int candi_dx1 = pos1 % vec.size();
            int candi_dx2 = (pos1 + vec.size() - 1) % vec.size();
            double candidate1 = getangle2(v, vec[candi_dx1]); //偏角候補１から角度を求める
            double candidate2 = getangle2(v, vec[candi_dx2]); //偏角候補２から角度を求める
            res = max({res, candidate1, candidate2});
        }
    }
    cout << fixed << setprecision(12);
    cout << res << ln;
}
