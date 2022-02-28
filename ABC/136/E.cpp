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

vector<long long> yakusu_rekkyo(long long N){
    vector<long long> res;
    for(long long i=1; i*i<=N; i++){
        if(N%i==0){
            res.push_back(i);
            if(N/i!=i)res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int n, k; cin >> n >> k;
    int sum = 0;
    vector<ll> A(n);
    rep(i, n){
        cin >> A[i];
        sum += A[i];
    }

    auto ya = yakusu_rekkyo(sum);
    int res = 0;
    for(auto x:ya){
        vector<int> X, Y;
        rep(i, n){
            int mod = A[i] % x;
            if(mod == 0)continue;
            X.push_back(mod);
            Y.push_back(x - mod);
        }
        sort(all(X));
        sort(all(Y), greater<int>());

        int cnt = 0, l = 0, r = (int)X.size() - 1;
        while(l < r){
            int val = min(X[l], Y[r]);
            cnt += val;
            X[l] -= val;
            if(X[l] == 0)l++;
            Y[r] -= val;
            if(Y[r] == 0)r--;
        }
        if(cnt <= k)res = x;
    }
    cout << res << ln;
}

