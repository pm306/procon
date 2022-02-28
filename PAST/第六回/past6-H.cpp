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
    ll N, M, K, Q; cin >> N >> M >> K >> Q;
    vector<ll> A, B; //A:not_kankiri, B:kankiri
    rep(i, N){
        ll p; int t; cin >> p >> t;
        if(t)B.push_back(p);
        else A.push_back(p);
    }
    sort(all(A));
    sort(all(B));

    ll res = LINF, sum = 0;
    if(M < A.size()){
        sum = accumulate(A.begin(), A.begin() + M, 0LL);
        res = sum;
        int key = 0;
        for(int i=M-1, j=0; i>=0 and j<B.size(); i--, j++){
            sum -= A[i];
            sum += B[j];
            if(key == 0){
                sum += Q;
                key = K;
            }
            chmin(res, sum);
            key--;
        }
    }
    else{
        sum = accumulate(all(A), 0LL);
        int j = 0, key = 0;
        for(; j+A.size()<M; j++){
            sum += B[j];
            if(key==0){
                sum += Q;
                key = K;
            }
            key--;
        }
        res = sum;

        for(int i=A.size() - 1; i>=0 and j<B.size(); i--, j++){
            sum -= A[i];
            sum += B[j];
            if(key == 0){
                sum += Q;
                key = K;
            }
            chmin(res, sum);
            key--;
        }

    }
    cout << res << ln;
}
