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
    string s; int k; cin >> s >> k;
    int n = s.size();

    vector<string> vec;
    auto dfs = [&](auto dfs, string t, vector<int> used) -> void{
        if(t.size() == n){
            vec.emplace_back(t);
            return;
        }
        rep(i, n)if(!used[i]++){
            dfs(dfs, t + s[i], used);
            used[i]--;
        }
    };
    vector<int> used(n);
    dfs(dfs, "", used);

    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    cout << vec[k-1] << ln;
}
