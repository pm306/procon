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



int main(){
    int n; string s; cin >> n >> s;

    const string list = "RGB";
    vector sum(3, vector<int>(n+1));
    rep(i, n){
        int idx = list.find(s[i]);
        sum[idx][i+1]++;
        rep(j, 3)sum[j][i+1] += sum[j][i];
    }

    ll res = 0;
    rep(i, n)rept(j, i+1, n){
        int a = list.find(s[i]), b = list.find(s[j]);
        if(a == b)continue;
        int c;
        if(a!=0 and b!=0)c = 0;
        if(a!=1 and b!=1)c = 1;
        if(a!=2 and b!=2)c = 2;
        res += sum[c][n] - sum[c][j+1];
        int k = j+(j-i);
        if(k<n and list.find(s[k]) == c)res--;
    }
    cout << res << ln;
}
