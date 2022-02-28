#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
実は貪欲法による解答もある。

・買う金額の一番安い町を選択
・その町から辿れる一番高値の街で売る
これを繰り返し、最も利益が出る値が答え。
※同じ町を二度通るとき、より安く買える街でその町を通っているので通る必要がない！　かしこい
*/

int main(){
    int n, m; cin >> n >> m;
    vector<ll> A(n); vector<pll> sort_A(n);
    rep(i, n){
        cin >> A[i];
        sort_A[i] = {A[i], i}; //金額, 街のインデックス
    }
    //金額の安い順にソート
    sort(all(sort_A));
    vector<vector<int>> G(n);
    rep(i, m){
        int x,y;cin >> x >> y; x--, y--;
        G[x].push_back(y);
    }

    //金額の安い街からBFSを行い、最も高い金額を探す
    //この時、一度訪れた町は二度訪れる必要がない。
    //そのため1頂点1度の探索で済む
    vector<int> seen(n);
    ll res = -LINF;
    rep(i, n){
        int s = sort_A[i].second;
        if(seen[s])continue;
        ll mx = -LINF;
        queue<int> que; que.push(s);
        while(!que.empty()){
            int v = que.front(); que.pop();
            //cout << "v:" << v << ln;
            for(auto e: G[v]){
                if(seen[e])continue;
                seen[e] = true;
                que.push(e);
                chmax(mx, A[e]);
            }
        }
        chmax(res, mx - A[s]);
    }
    cout << res << ln;
}
