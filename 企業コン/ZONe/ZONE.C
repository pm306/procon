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

/*
最小値の最大化、なので二分探索、という発想はOK
パターンを32通りに圧縮して、「パターン」を3重ループして存在判定する、という方式を採る。状態の重複はないのでこれでOK
ビット演算苦手だわ……
*/


const int NUM = 32;

int main(){
    int N; cin >> N;
    vector<vector<int>> scores(N, vector<int>(5));
    rep(i, N){
        rep(j, 5){
            cin >> scores[i][j];
        }
    }
    auto getMask = [&](int a, int lim) -> int{
        int res = 0;
        rep(i, 5){
            if(scores[a][i] >= lim) res += 1<<i;
        }
        return res;
    };

    auto check = [&](int x) -> bool{
        int cnt[NUM]{};
        rep(i, N){
            cnt[getMask(i, x)]++;
        }
        rep(a, NUM){
            rep(b, NUM){
                rep(c, NUM){
                    if((a | b | c) == NUM - 1 and cnt[a] and cnt[b] and cnt[c])return true;
                }
            }
        }
        return false;
    };

    int ok = 0, ng = INF;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << ok << ln;
}

