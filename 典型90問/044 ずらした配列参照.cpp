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
    int N, Q; cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }

    int shift = 0; // 右にshift項ずれている = 左にshift項ずらして考える
    vector<int> ans;
    while(Q--){
        int t, x, y; cin >> t >> x >> y; x--, y--;
        if(t==1){
            swap(A[(x+N-shift)%N], A[(y+N-shift)%N]);
        }
        else if(t==2){
            shift = (shift + 1) % N;
        }
        else if(t==3){
            ans.push_back(A[(x+N-shift)%N]);
        }
    }
    for(auto a:ans)cout << a << " " << ln;
}
