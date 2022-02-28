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
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll solve(){
    int N; cin >> N;
    vector<ll> A(N); rep(i, N)cin >> A[i];

    ll res = 0;
    for(int i=0; i<N-1; i++){
       // cout << A[i] << ":" << A[i+1] << ln;
        if(A[i]<A[i+1])continue;
        if(A[i]==A[i+1]){
            A[i+1] *= 10;
            res++;
            continue;
        }
        int ketaA = to_string(A[i]).size(), ketaB = to_string(A[i+1]).size();
        ll sa = ketaA - ketaB;
        ll a = A[i] / (ll)pow(10, sa), b = A[i+1];
        //cout << "ketaA:" << ketaA << " ketaB:" << ketaB << "sa:" << sa << ln;
        if(a>b){
            A[i+1] *= (ll)pow(10, sa+1); res += sa+1;
        }else if(a<b){
            A[i+1] *= (ll)pow(10, sa); res += sa;
        }else{
            string tmp = to_string(A[i] % (ll)pow(10, sa));
            if(whole(count, tmp, '9') == sa){
                A[i+1] *= (ll)pow(10, sa+1); res += sa+1;
            }else{
                A[i+1] = A[i] + 1;
                res += sa;
            }
        }
        //cout << "res:" << res << ln;
    }
    return res;
}

int main(){
    int T; cin >> T;
    vector<ll> ans;
    rep(t, T){
        ans.push_back(solve());
    }

    rep(i, ans.size()){
        cout << "Case #" << i+1 << ": " << ans[i] << ln;
    }
}
