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

int main(){
    int N, M; cin >> N >> M;
    map<ll, vector<ll>> mp;
    rep(i, M){
        ll x, y; cin >> x >> y;
        y += M + 1 - N; //白ポーンを(0, N)->(0, M+1)にずらして考えているので、黒ポーンのy座標も合わせる
        if(1 <= y and y <= M*2+1){ //初期値から高々M個隣のポーンしか移動に影響しないので残りは捨てる
            mp[x].push_back(y);
        }
    }

    vector<int> A(M*2+3);
    A[M+1] = true;
    for(auto m: mp){
        vector<pll> changes;
        for(auto y: m.second){
            changes.push_back({y, A[y-1] or A[y+1]});
        }
        for(auto c: changes){
            A[c.first] = c.second;
        }
    }
    cout << accumulate(all(A), 0) << ln;
}
