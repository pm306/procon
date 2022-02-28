#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
得点の高い順に、貪欲に選んでいく
優先度付きキューを使って値が大きい順にＫ回選べばよい。
部分点を取った場合は満点を取る選択肢をキューに入れる。
*/


int main(){
    int N, K; cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, N)cin >> A[i] >> B[i];

    priority_queue<pll> que; //score, index
    rep(i, N){
        que.push({B[i], i});
    }

    ll res = 0;
    vector<int> check(N); // is_get B
    while(K--){
        ll score = que.top().first;
        int idx = que.top().second;
        que.pop();
        res += score;
        if(!check[idx]++){
            que.push({A[idx] - B[idx], idx});
        }
    }
    cout << res << ln;
}

