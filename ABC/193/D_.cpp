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

ll calcscore(vector<int> counter){ //1~9の出現回数
    ll res = 0;
    for(int i=1; i<=9; i++){
        res += i * pow(10, counter[i]);
    }
    return res;
}

int main(){
    int K; string S, T;
    cin >> K >> S >> T;
    vector<int> countT(10), countA(10), card(10);
    rep(i, 4){
        countT[S[i]-'0']++;
        countA[T[i]-'0']++;
        card[S[i]-'0']++;
        card[T[i]-'0']++;
    }

    double res = 0;
    for(int i=1; i<=9; i++){
        countT[i]++;
        for(int j=1; j<=9; j++){
            countA[j]++;
            //if takahashi > aoki:
            if(calcscore(countT) > calcscore(countA)){
                //res += 確率
                // K-(場に出てるカードの枚数) / 9K-8
                double pt = (double)(K-card[i]) / (9*K-8);
                card[i]++;
                double pa = (double)(K-card[j]) / (9*K-9);
                res += pt * pa;
                card[i]--;
            }
            countA[j]--;
        }
        countT[i]--;
    }
    cout << fixed << setprecision(12);
    cout << res << ln;
}
