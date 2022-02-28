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
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int op(int a, int b){
    return a ^ b;
}
int e(){
    return 0;
}

int main(){
    int N, Q; cin >> N >> Q;
    segtree<int, op,e> seg(N);
    rep(i, N){
        int a; cin >> a;
        seg.set(i, a);
    }
    vector<int> ans;
    while(Q--){
        int t; cin >> t;
        int x, y; cin >> x >> y; x--;
        if(t==1){
            seg.set(x, seg.get(x) ^ y);
        }
        else{
            ans.push_back(seg.prod(x, y));
        }
    }
    fore(a, ans)cout << a << ln;
}
