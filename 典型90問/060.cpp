#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
using vll = vector<long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


template<class T> int LIS(vector<T>& a, vector<T>& v, bool is_strong = true){
    const T inf = 1<<30;
    int n = (int)a.size();
    vector<T> dp(n, inf);
    for(int i=0; i<n; i++){
        int pos, cnt = 0;
        if(is_strong)pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        else pos = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[pos] = a[i];
        v[i] = pos + 1;
    }
    return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}

int main(){
    int N; cin >> N;
    vector<int> A(N);
	rep(i, N) cin >> A[i];

    vector<int> P(N), Q(N);
    LIS(A, P);
    reverse(all(A));
    LIS(A, Q);

    int res = 0;
    rep(i, N){
        chmax(res, P[i] + Q[N-1-i] - 1);
    }
    cout << res << ln;
}
