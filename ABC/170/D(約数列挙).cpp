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

// 他の数で割り切れない　とは
// 割り切れる数 = 約数
// aの約数がa以外に存在しない(重複はありうる)
// ----
// aを約数列挙して、存在判定する

vector<long long> yakusu_rekkyo(long long N){
    vector<long long> res;
    for(long long i=1; i*i<=N; i++){
        if(N%i==0){
            res.push_back(i);
            if(N/i!=i)res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> A(n), C(1e6+10);
    rep(i, n){
        cin >> A[i];
        C[A[i]]++;
    }

    int res = 0;
    for(auto a:A){
        C[a]--;
        auto ya = yakusu_rekkyo(a);
        bool not_div = true;
        for(auto b:ya){
            if(C[b])not_div = false;
        }
        res += not_div;
        C[a]++;
    }
    cout << res << ln;
}
