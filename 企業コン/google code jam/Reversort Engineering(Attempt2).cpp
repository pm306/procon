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


vector<int> solve(){
    int N, C; cin >> N >> C;

    if(C < N-1 or C > N*(N+1)/2 - 1){
        vector<int> res{-1};
        return res;
    }

    C -= N-1;
    vector<int> A;
    for(int i=N-1; i>0; i--){
        if(C>=i){
            A.push_back(i);
            C -= i;
        }else{
            A.push_back(C);
            C = 0;
        }
    }

    vector<int> res(N); iota(all(res),1);
    for(int i=N-2; i>=0; i--){
        int left = i, right = i+A[i]+1;
        reverse(res.begin()+left, res.begin()+right);
    }
    return res;
}

int main(){
    int T; cin >> T;
    vector<vector<int>> ans;
    rep(t, T){
        ans.push_back(solve());
    }
    rep(i, ans.size()){
        cout << "Case #" << i+1 << ": ";
        if(ans[i][0] == -1)cout << "IMPOSSIBLE" << ln;
        else{
            for(auto a:ans[i]){
                cout << a << " ";
            }
            cout << ln;
        }
    }
}
