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

int op(int a, int b){return max(a, b);}
int e(){return -1;}
int target;
bool f(int x){return x < target;}

int main(){
    int n, q; cin >> n >> q;
    segtree<int, op, e> seg(n);
    rep(i, n){
        int a; cin >> a;
        seg.set(i, a);
    }

    vector<int> ans;
    while(q--){
        int t, a, b; cin >> t >> a >> b; a--;
        if(t == 1){
            seg.set(a, b);
        }
        if(t == 2){
            int res = seg.prod(a, b);
            ans.emplace_back(res);
        }
        if(t == 3){
            target = b;
            int res = seg.max_right<f>(a) + 1;
            ans.emplace_back(res);
        }
    }
    fore(a, ans)cout << a << ln;
}
