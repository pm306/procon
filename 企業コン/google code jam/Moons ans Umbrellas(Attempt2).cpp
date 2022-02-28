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



int solve(){
int X, Y; string S; cin >> X >> Y >> S;
    //連続する[?]を取り除く
    rep(i, S.size()-1){
        if(S[i] == '?' and S[i+1] == '?'){
            S.erase(i, 1);
            i--;
        }
    }
    //処理の簡略化のため適当な文字で挟む
    S = "X" + S + "X";
    int res = 0;
    for(int i=1; i<S.size()-1; i++){
        if(S[i]=='?'){
            if(S[i-1]=='C' and S[i+1] == 'J')res += X;
            if(S[i-1]=='J' and S[i+1] == 'C')res += Y;
        }else{
            if(S[i]=='C' and S[i+1] == 'J')res += X;
            if(S[i]=='J' and S[i+1] == 'C')res += Y;
        }
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
