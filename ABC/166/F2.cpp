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



int main(){
    int n; cin >> n;
    ll A[3]; rep(i, 3) cin >> A[i];
    vector<pair<int, int>> Q(n);
    rep(i, n){
        string s; cin >> s;
        int a = s[0] - 'A', b = s[1] - 'A';
        Q[i] = {a, b};
    }

    ll sum = A[0] + A[1] + A[2];
    if(A[Q[0].first] == 0 and A[Q[0].second] == 0){
        cout << "No" << ln;
        return 0;
    }

    vector<char> ans(n);
    if(sum == 0){
        cout << "No" << ln;
        return 0;
    }
    else if(sum == 1){
        rep(i, n){
            auto [a, b] = Q[i];
            if(A[a] == 0 and A[b] == 0){
                cout << "No" << ln;
                return 0;
            }
            if(A[a]>A[b]){
                ans[i] = (char)('A'+b);
                A[a]--;
                A[b]++;
            }
            else{
                ans[i] = (char)('A'+a);
                A[a]++;
                A[b]--;
            }
        }
    }
    else if(sum == 2){
        rep(i, n){
            auto [a, b] = Q[i];
            if(A[a] == 0 and A[b] == 0){
                cout << "No" << ln;
                return 0;
            }
            else if(A[a] == 0 and A[b] > 0 or A[a] > 0 and A[b] == 0){
                if(A[a]>A[b]){
                    ans[i] = (char)('A'+b);
                    A[a]--;
                    A[b]++;
                }
                else{
                    ans[i] = (char)('A'+a);
                    A[a]++;
                    A[b]--;
                }
            }
            //(1, 1)
            else{
                if(i == n-1)ans[i] = (char)('A'+a);
                else{
                    auto [na, nb] = Q[i+1];
                    if(a == na or a == nb){
                        ans[i] = (char)('A'+a);
                        A[a]++;
                        A[b]--;
                    }
                    else{
                        ans[i] = (char)('A'+b);
                        A[a]--;
                        A[b]++;
                    }
                }
            }
        }
    }
    else{
        rep(i, n){
            auto [a, b] = Q[i];
            if(A[a]>A[b]){
                ans[i] = (char)('A'+b);
                A[a]--;
                A[b]++;
            }
            else{
                ans[i] = (char)('A'+a);
                A[a]++;
                A[b]--;
            }
        }
    }
    cout << "Yes" << ln;
    fore(a, ans)cout << a << ln;
}

