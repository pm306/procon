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
////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(){
    string s; cin >> s;
    int cnt[10]{};
    fore(a, s)cnt[a-'0']++;

    if(s.size() == 1){
        cout << (s[0] == '8' ? "Yes" : "No") << ln;
    }
    else if(s.size() == 2){
        int a = stoi(s);
        reverse(all(s));
        int b = stoi(s);
        cout << (a%8==0 or b%8==0 ? "Yes" : "No") << ln;
    }
    else{
        for(int i=112; i<1000; i+=8){
            string t = to_string(i);
            int cnt2[10]{};
            fore(a, t)cnt2[a-'0']++;

            bool ok = true;
            rep(i, 10)if(cnt[i]<cnt2[i])ok = false;
            if(ok){
                cout << "Yes" << ln;
                return 0;
            }
        }
        cout << "No" << ln;
    }
}
