#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void dfs(vector<string>& V, int index, string S){
    if(index >= S.size()){
        V.push_back(S);
        return;
    }

    if(S[index]== '?'){
        S[index] = 'C';
        dfs(V, index+1, S);
        S[index] = 'J';
        dfs(V, index+1, S);
    }else{
        dfs(V, index+1, S);
    }
}

int solve(){
    int res = INF;

    int X, Y; string S; cin >> X >> Y >> S;
    //全探索
    vector<string> V;
    dfs(V, 0, S);
    for(auto vec: V){
        int cost = 0;
        rep(i, vec.size()-1){
            if(vec[i] == 'C' and vec[i+1] == 'J')cost += X;
            if(vec[i] == 'J' and vec[i+1] == 'C')cost += Y;
        }
        chmin(res, cost);
    }

    return res;
}

int main(){
    int T; cin >> T;
    vector<int> ans;
    rep(t, T){
        ans.push_back(solve());
    }
    rep(i, ans.size()){
        cout << "Case #" << i+1 << ": " << ans[i] << ln;
    }
}
