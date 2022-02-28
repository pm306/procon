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

int op(int a, int b){return min(a, b);}
int e(){return 1<<30;}

int main(){
    int n, q; cin >> n >> q;

    segtree<int, op, e> seg(n); //区間最小値を取る
    map<int, set<int>> mp; //値ごとのインデックス
    rep(i, n){
        int a; cin >> a;
        seg.set(i, a);
        mp[a].insert(i);
    }

    vector<vector<int>> ans(q); int idx = 0;
    while(q--){
        int t, x, y; cin >> t >> x >> y; x--;
        if(t == 1){
            int val = seg.get(x);
            mp[val].erase(x);
            seg.set(x, y);
            mp[y].insert(x);

        }
        else{
            int mi = seg.prod(x, y); //[x, y)
            auto it_s = mp[mi].lower_bound(x);
            auto it_t = mp[mi].lower_bound(y);
            for(auto it = it_s; it != it_t; it++){
                ans[idx].push_back(*it + 1);
            }
            idx++;
        }
    }

    rep(i, ans.size()){
        if(ans[i].empty())break;
        cout << ans[i].size() << " ";
        for(auto a:ans[i]){
            cout << a << " ";
        }
        cout << ln;
    }

    // set<int> st{3,1,6,5,8,14,11,9}; //[5,13)まで取得したい
    // auto it_s = st.lower_bound(5);
    // auto it_t = st.lower_bound(13);
    // for(auto it = it_s; it != it_t; it++){
    //     cout << *it << ln;
    // }
}
