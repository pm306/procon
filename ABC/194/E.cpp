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

const int MAX = 1500010;

int main(){
    int n, m; cin >> n >> m;
    set<int> nonNum;
    vector<int> C(MAX), A(n);
    rep(i, n){
        cin >> A[i];
        if(i<m)C[A[i]]++;
    }
    rep(i, MAX){
        if(C[i]==0)nonNum.insert(i);
    }

    int res = *nonNum.begin();
    for(int i=m; i<n; i++){
        C[A[i]]++;
        nonNum.erase(A[i]);
        C[A[i-m]]--;
        nonNum.insert(A[i-m]);
        chmin(res, *nonNum.begin());
    }
    cout << res << ln;
}
