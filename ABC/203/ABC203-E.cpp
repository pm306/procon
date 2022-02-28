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
    ll N, M; cin >> N >> M;
    vector<pll> pawn(M);
    rep(i, M){
        ll x, y; cin >> x >> y;
        pawn[i] = {x, y};
    }
    sort(all(pawn));

    set<ll> pos{N};
    vector<ll> ins, era;
    ll pre_x = -1;
    for(auto p:pawn){
        ll x = p.first, y = p.second;
        if(x != pre_x){
            pre_x = x;
            for(auto p:era)pos.erase(p);
            for(auto p:ins)pos.insert(p);
            ins.clear();
            era.clear();
        }
        //not find
        if(pos.find(y-1) == pos.end() and pos.find(y+1) == pos.end()){
            era.push_back(y);
        }
        //find
        else{
            ins.push_back(y);
        }
    }
    for(auto p:era)pos.erase(p);
    for(auto p:ins)pos.insert(p);
    cout << pos.size() << ln;
}
