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

// 24 11 8 3 16
// 48, 72, ... 24によってだめになる数
// 22, 33, ... 11によってだめになる数
// 16, 24, ...　8によって
// 6, 9, ...  　3によって
// 32, 48, ... 16によって

// 同じ値が複数ある場合は無条件アウト

int main(){
    int n; cin >> n;
    vector<int> A(n), cnt(1e6+10), NG(1e6+10);
    rep(i, n){
        cin >> A[i];
        cnt[A[i]]++;
        if(cnt[A[i]] == 1){
            for(int j=A[i]*2; j<=1e6; j+=A[i]){
                NG[j] = true;
            }
        }
    }

    int res = 0;
    for(auto a:A){
        if(cnt[a]>1)continue;
        if(!NG[a])res++;
    }
    cout << res << ln;
}
