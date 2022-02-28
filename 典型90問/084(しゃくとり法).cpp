#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    int N; string S; cin >> N >> S;

    ll res = 0, r = 0;
    int cnt[2]{};
    for(int l=0; l<N; l++){
        while(r<N){
            if(cnt[0] and cnt[1])break;
            char c = S[r++];
            if(c=='o')cnt[0]++;
            else cnt[1]++;
        }
        if(cnt[0] and cnt[1])res += N-r+1;

        if(l==r)r++;
        if(S[l]=='o')cnt[0]--;
        else cnt[1]--;
    }
    cout << res << ln;
}

