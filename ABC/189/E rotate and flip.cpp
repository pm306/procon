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

using mat = vector<vector<ll>>;
//行列積を求める
mat mul(mat& A, mat& B){
    mat C(A.size(), vector<ll>(B[0].size()));
    for(int i=0; i<A.size(); i++){
        for(int k=0; k<B.size(); k++){
            for(int j=0; j<B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}

mat op1(mat P){
    mat Q = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
    return mul(Q, P);
}
mat op2(mat P){
    mat Q = {{0,-1,0}, {1, 0, 0}, {0, 0, 1}};
    return mul(Q, P);
}
mat op3(mat P, ll p){
    mat Q = {{-1, 0, 2*p}, {0, 1, 0}, {0, 0, 1}};
    return mul(Q, P);
}
mat op4(mat P, ll p){
    mat Q = {{1, 0, 0}, {0, -1, 2*p}, {0, 0, 1}};
    return mul(Q, P);
}

int main(){
    int n; cin >> n;
    vector<ll> X(n), Y(n); rep(i, n)cin >> X[i] >> Y[i];

    int m; cin >> m;
    vector<pair<int, ll>> op(m);
    rep(i, m){
        cin >> op[i].first;
        if(op[i].first >= 3)cin >> op[i].second;
    }

    int q; cin >> q;
    vector<tuple<int, int, int>> query;
    rep(i, q){
        int a, b; cin >> a >> b; b--;
        query.emplace_back(a, b, i);
    }

    sort(all(query));
    vector<pair<ll, ll>> ans(q);
    int qi = 0;
    while(qi < q){
        auto [a, b, i] = query[qi];
        if(a > 0)break;
        ans[i] = {X[b], Y[b]};
        qi++;
    }

    mat E{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    rep(i, m){
        auto [num, line] = op[i];
        if(num == 1)E = op1(E);
        if(num == 2)E = op2(E);
        if(num == 3)E = op3(E, line);
        if(num == 4)E = op4(E, line);

        while(qi < q){
            auto [a, b, idx] = query[qi];
            if(a > i + 1)break;
            mat pos = {{X[b]}, {Y[b]}, {1}};
            mat res = mul(E, pos);
            ans[idx] = {res[0][0], res[1][0]};
            qi++;
        }
    }

    for(auto [x, y]:ans)cout << x << " " << y << ln;
}
