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
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
・インクリメント・デクリメントを式評価に先んじて行いたい時は先頭につける
・map.eraseでキーを削除できる
・map.sizeでサイズを取得できる
*/

int main(){
    int N, K; cin >> N >> K;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    map<int, int> mp;
    rep(i, K){
        mp[A[i]]++;
    }
    int res = mp.size();
    rept(i, K, N){
        mp[A[i]]++;
        if(--mp[A[i-K]] == 0)mp.erase(A[i-K]);
        chmax(res, (int)mp.size());
    }
    cout << res << ln;
}
