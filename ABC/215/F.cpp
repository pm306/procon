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



int main(){
    int n; cin >> n;
    vector<pair<int, int>> pos(n);
    rep(i, n)cin >> pos[i].first >> pos[i].second;

    sort(all(pos)); //x座標でソート
    vector<int> X(n), Y(n);
    rep(i, n)X[i] = pos[i].first, Y[i] = pos[i].second;

    //距離(min(a, b))がx以上となる座標のペアが存在するか？
    auto f = [&](int d) -> bool{
        set<int> st;
        int l = 0;
        for(int r=1; r<n; r++){
            while(l<n){
                if(X[r] - X[l] < d)break;
                st.insert(Y[l++]);
            }

            if(st.empty())continue;
            if(Y[r] - *st.begin() >= d or *st.rbegin() - Y[r] >= d)return true;
        }
        return false;
    };

    int lo = -1, hi = 1<<30;
    while(hi-lo>1){
        int mi = (hi+lo)/2;
        if(f(mi))lo = mi;
        else hi = mi;
    }
    cout << lo << ln;
}
