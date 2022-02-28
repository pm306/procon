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
    vector<string> A(N); rep(i, N)cin >> A[i];

    ll res = 0;
    for(int i=0; i<N-1; i++){
        int ketaA = A[i].size(), ketaB = A[i+1].size();
        if(ketaA < ketaB)continue;
        if(ketaA == ketaB){
            int big = 0;
            rep(j, ketaA){
                if(A[i][j]> A[i+1][j]){
                    break;
                }
                if(A[i][j]<A[i+1][j]){
                    big = 1;
                    break;
                }
            }
            if(big==1)continue;
            if(big==0){
                A[i+1].push_back('0');
                res++;
                continue;
            }
        }
        int sa = ketaA - ketaB;
        ll a = stoi(A[i].substr(0, ketaB)), b = stoi(A[i+1]);
        if(a>b){
            rep(j, sa+1){
                A[i+1].push_back('0');
                res++;
            }
        }else if(a<b){
            rep(j, sa){
                A[i+1].push_back('0');
                res++;
            }
        }else{
            string t = ""; bool over = false;
            for(int j=ketaA-1; j>=ketaA-sa; j--){
                if(over){
                    t += A[i][j];
                }else{
                    //cout << "A[i][j]:" << A[i][j] << ln;
                    if(A[i][j]=='9'){
                        t += '0';
                    }else{
                        char tmp = A[i][j] + 1;
                        over = true;
                        t += tmp;
                    }
                }
            }
            if(!over)t += '1';
            whole(reverse, t);
            res += t.size();
            A[i+1] += t;
            //cout << "t:" << t << ln;
        }
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
