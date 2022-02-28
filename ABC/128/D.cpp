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

/*
・取れるだけ取ってから負の価値の宝石を要らない順に戻すのが最善。(戻してから取るメリットがない)
・左から取る、右から取る、で全探索
・for文の中でcontinueを上手く使って、宝石を取りすぎたり条件を違反したりするのを防ぐ
*/

int N, K, V[50];
int main(){
    cin >> N >> K;
    rep(i, N)cin >> V[i];

    int res = 0;
    rep(left, N+1){
        rep(right, N+1){
            if(left + right > N)continue; //宝石が足りない
            int rest = K - (left + right);
            if(rest < 0)continue; // 操作回数オーバー

            vector<int> houseki;
            rep(i, left)houseki.push_back(V[i]);
            rep(i, right)houseki.push_back(V[N-1-i]);
            sort(all(houseki), greater<int>());

            rep(i, rest){
                if(houseki.empty() or houseki.back()>0)break; //負の宝石がなくなれば終了
                houseki.pop_back();
            }
            chmax(res, accumulate(all(houseki), 0));
        }
    }
    cout << res << ln;
}
