#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int N; cin >> N;
    vector<ll> Num(3); rep(i, 3)cin >> Num[i];
    vector<string> S(N);
    rep(i, N){
        cin >> S[i];
    }

    ll sum = whole(accumulate, Num, 0LL);
    vector<string> ans(N);
    if(sum==0){
        cout << "No" << ln;
        return 0;
    }
    if(sum==1){
        rep(i, N){
            int a = S[i][0]-'A', b = S[i][1]-'A';
            if(Num[a]==1){
                Num[a]--;
                Num[b]++;
                ans[i] = S[i][1];
            }else if(Num[b]==1){
                Num[a]++;
                Num[b]--;
                ans[i] = S[i][0];
            }else{
                cout << "No" << ln;
                return 0;
            }
        }
    }
    if(sum==2){
        rep(i, N){
            int a = S[i][0]-'A', b = S[i][1]-'A';
            if(Num[a]==0 and Num[b]==0){
                cout << "No" << ln;
                return 0;
            }
            if(Num[a]==2 or Num[a]==1 and Num[b]==0){
                Num[a]--;
                Num[b]++;
                ans[i] = S[i][1];
            }
            else if(Num[b]==2 or Num[a]==0 and Num[b]==1){
                Num[a]++;
                Num[b]--;
                ans[i] = S[i][0];
            }
            else{
                if(i==N-1){
                    if(!Num[a]){
                        ans[i] = S[i][0];
                    }else{
                        ans[i] = S[i][1];
                    }
                }
                else{
                    int na = S[i+1][0]-'A', nb = S[i+1][1]-'A';
                    if(a==na or a==nb){
                        Num[a]++;
                        Num[b]--;
                        ans[i] = S[i][0];
                    }else{
                        Num[a]--;
                        Num[b]++;
                        ans[i] = S[i][1];
                    }
                }
            }
        }
    }
    if(sum>2){
         rep(i, N){
            int a = S[i][0]-'A', b = S[i][1]-'A';
            if(Num[a]==0 and Num[b]==0){
                cout << "No" << ln;
                return 0;
            }
            if(Num[a]==0 or Num[a]<Num[b]){
                Num[a]++;
                Num[b]--;
                ans[i] = S[i][0];
            }else if(Num[b]==0 or Num[a]>=Num[b]){
                Num[a]--;
                Num[b]++;
                ans[i] = S[i][1];
            }
        }
    }
    cout << "Yes" << ln;
    for(auto a:ans)cout << a << ln;
}
