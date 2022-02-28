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

int calcCost(vector<int> array){
    int res = 0;
    for(int i=0; i<array.size()-1; i++){
        int min_index = -1, min_number = INF;
        for(int j=i; j<array.size(); j++){
            if(chmin(min_number, array[j]))min_index = j;
        }
        res += min_index - i + 1;
        reverse(array.begin()+i, array.begin()+min_index+1);
    }
    return res;
}

vector<int> solve(){
    int N, C; cin >> N >> C;

    vector<int> Array; //sorted
    for(int i=1; i<=N; i++)Array.push_back(i);
    do {
        if(calcCost(Array) == C){
            return Array;
        }
    } while (next_permutation(all(Array)));

    vector<int> impossible{-1};
    return impossible;
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
