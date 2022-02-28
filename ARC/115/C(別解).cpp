#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
約数系
条件の厳しいほうから見てく

A[1] : 1は全ての数の約数なので2~Nの取れる最小値は2　この時点で2以上の最小値が2になる
A[2] : 2は4,6,8,....の約数なのでそれらの取れる値はA[2] + 1
A[n] : nはnの倍数の約数なので、2n... についてそれらの取れる最小値はA[n] + 1

このように最小値を更新する

昔は
各nが被ってはいけない数は、nの約数の個数なので約数列挙してる

*/

int main(){
    int N; cin >> N;
    vector<int> minNum(N+1); minNum[1] = 1;
    rept(i, 1, N+1){
        for(int j=i*2; j<=N; j += i){
            minNum[j] = minNum[i]+1;
        }
    }

    rept(i, 1, N+1)cout << minNum[i] << " ";
    cout << ln;
}
