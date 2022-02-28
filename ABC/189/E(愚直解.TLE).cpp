#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
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

//二次元座標を90度回転させた時の座標を返す
pair<ll, ll> rotate(ll y, ll x, bool clockwize=true){
    if(clockwize)return {-x, y};
    else return {x, -y};
}
//二次元座標をx=n(y=n)に線対称になるように移動させる
pair<ll, ll> line_smartly(ll y, ll x, ll n, bool line_x =true){
    if(line_x)return {y, n + (n - x)};
    else return {n + (n - y), x};
}
int main(){
    int n; cin >> n;
    vector<ll> X(n), Y(n); rep(i, n)cin >> X[i] >> Y[i];

    int m; cin >> m;
    vector<pair<int, ll>> op;
    rep(i, m){
        int a, b = -1; cin >> a;
        if(a == 3 or a == 4) cin >> b;
        op.emplace_back(a, b);
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
    rep(i, m){
        auto [num, line] = op[i];
        if(num == 1 or num == 2){
            rep(j, n){
                auto [y, x] = rotate(Y[j], X[j], num==1);
                Y[j] = y, X[j] = x;
            }
        }
        else{
            rep(j, n){
                auto [y, x] = line_smartly(Y[j], X[j], line, num==3);
                Y[j] = y, X[j] = x;
            }
        }
        while(qi < q){
            auto [a, b, idx] = query[qi];
            if(a > i + 1)break;
            ans[idx] = {X[b], Y[b]};
            qi++;
        }
    }

    for(auto [x, y]:ans)cout << x << " " << y << ln;
}
