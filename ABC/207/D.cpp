#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
////////////////////////////////////////////////////////////////////////////////////////////////////////

int distance(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

using mat = vector<vector<double>>;
//行列積を求める
mat mul(mat& A, mat& B){
    mat C(A.size(), vector<double>(B[0].size()));
    for(int i=0; i<A.size(); i++){
        for(int k=0; k<B.size(); k++){
            for(int j=0; j<B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
            }
        }
    }
     return C;
}

//y, xをθ = r(ラジアン)だけ回転する
mat rotate(double x, double y, double r){
    mat M = {{cos(r), -(sin(r))}, {sin(r), cos(r)}};
    mat pos = {{(double)x}, {(double)y}};
    return mul(M, pos);
}

int main(){
    int n; cin >> n;
    vector<pair<double, double>> A(n), B(n);
    rep(i, n)cin >> A[i].first >> A[i].second;
    rep(i, n)cin >> B[i].first >> B[i].second;

    if(n == 1){
        cout << "Yes" << ln;
        return 0;
    }

    string res = "No";
    //S0, S1に対応するTi, Tjを全探索する
    rep(i, n)rep(j, n){
        if(i == j)continue;
        auto S = A, T = B;
        auto [x1, y1] = S[0];
        auto [x2, y2] = S[1];
        auto [x3, y3] = T[i];
        auto [x4, y4] = T[j];
        if(distance(x1, y1, x2, y2) != distance(x3, y3, x4, y4))continue;

        //手順1
        rep(k, n)S[k].first -= x1, S[k].second -= y1;
        rep(k, n)T[k].first -= x3, T[k].second -= y3;

        double kaku = atan2(S[1].second, S[1].first) - atan2(T[j].second, T[j].first); //偏角の差
        vector<pair<double, double>> rT; //回転後のTの座標
        rep(k, n){
            auto pos = rotate(T[k].first, T[k].second, kaku);
            rT.emplace_back(pos[0][0], pos[1][0]);
        }

        bool ok = true;
        rep(k, n){
            bool match = false;
            auto [x, y] = S[k];
            rep(l, n){
                auto [xx, yy] = rT[l];
                if(abs(x - xx) < 0.01 and abs(y - yy) < 0.01)match = true;
            }
            if(!match)ok = false;
        }
        if(ok)res = "Yes";
    }
    cout << res << ln;
}
