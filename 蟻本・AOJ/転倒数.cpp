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
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
転倒数を数え上げる
AOJのジャッジにはACLが通らないので注意
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=jp
*/

//座標圧縮 配列Vを0-indexedで圧縮した配列retを返す
template<class T> vector<int> CompressNumber(vector<T> V){
    vector<T> vals = V;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end()); //重複削除

    vector<int> ret;
    for(auto v: V){
        int idx = lower_bound(vals.begin(), vals.end(), v) - vals.begin();
        ret.push_back(idx);
    }
    return ret;
}

int main(){
    int n; cin >> n;
    vector<int> A(n); rep(i, n)cin >> A[i];

    A = CompressNumber(A);

    fenwick_tree<int> BIT(n);
    ll res = 0;
    rep(i, n){
        res += i - BIT.sum(0, A[i]);
        //res += BIT.sum(A[i], n+1);
        BIT.add(A[i], 1);
    }
    cout << res << ln;
}

