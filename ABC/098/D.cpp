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
問題文を言い換えると[桁ごとに1が2回以上出現しない区間]
しゃくとり法で求められる
breakの場所には気を付けよう！
*/

int main(){
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    ll res = 0; int r=0;
    vector<int> bits(20);
    for(int l=0; l<N; l++){
        while(r<N){
            vector<int> plus(20);
            bool ok = true;
            rep(mask, 20){
                plus[mask] += A[r]>>mask&1;
                if(bits[mask] and plus[mask])ok = false;
            }
            if(!ok)break;
            rep(i, 20)bits[i] += plus[i];
            r++;
        }
        res += r - l;

        if(l==r)r++;
        rep(mask, 20){
            bits[mask] -= A[l]>>mask&1;
        }
    }
    cout << res << ln;
}

