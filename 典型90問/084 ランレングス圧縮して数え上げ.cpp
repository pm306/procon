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

using pll = pair<ll, ll>;

int main(){
    ll N; string S; cin >> N >> S;

    vector<pll> V;
    ll cnt = 0;
    rep(i, S.size()){
        cnt++;
        if(i == (int)S.size()-1 or S[i] != S[i+1]){
            V.emplace_back(S[i], cnt);
            cnt = 0;
        }
    }

    ll yo = 0;
    for(auto[s, cnt]:V){
        yo += cnt * (cnt - 1) / 2;
    }
    cout << N * (N-1) / 2 - yo << ln;
}

