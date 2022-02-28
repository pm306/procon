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

//使える数字を列挙して、絶対値の大きい順に使って0に近づける？

int main(){
    ll N; cin >> N;

    vector<ll> res;
    ll num = 1;
    while(N){
        ll mod = N % (num * 3);
        if(mod == num){
            res.push_back(num);
            N -= num;
            if(res.size() > 1 and res.back() == res[res.size()-2]){
                //重複
                ll tmp = res.back();
                res.pop_back();
                res.pop_back();
                res.push_back(-num);
                res.push_back(tmp * 3);
            }
        }
        else if(mod == num*2){
            res.push_back(-num);
            res.push_back(num*3);
            N -= num * 2;
        }
        num *= 3;
    }
    vector<ll> ans;
    rep(i, res.size()){
        if(i < res.size()-1 and abs(res[i]) == abs(res[i+1])){
            i += 1;
            continue;
        }
        ans.push_back(res[i]);
    }

    cout << ans.size() << ln;
    fore(a, ans)cout << a << " "; cout << ln;
}
