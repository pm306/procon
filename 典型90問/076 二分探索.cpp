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

/*
累積和(区間和)の使い方　教育的問題

【考察】
・円形の区間和は同じ区間を2回つなげて考えると楽
・Aの総和が10の倍数でないとき、自明にNo
・素朴に探索するとO(N^2)

・始点を決め、始点からの区間和がちょうどsum(A)/10である区間があるか知りたい
→二分探索
★始点ごとの区間和を取ると間に合わないので、始点を0に固定して問題を
「0個目のピースから考えて、区間和がsum(A)/10 + S[i](i個目の直前までの区間和)
と言い換えると嬉しくなる。(始点がずれるので0に統一するのはたまにある)
*/


int main(){
    int N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    vector<ll> S(N*2+1);
    rep(i, N)S[i+1] = S[i] + A[i];
    rep(i, N)S[N+i+1] = S[N+i] + A[i];

    if(S[N]%10){
        cout << "No" << ln;
        return 0;
    }

    rep(i, N){
        ll num = S[N] / 10 + S[i];
        int p = lower_bound(all(S), num) - S.begin();
        if(S[p] == num){
            cout << "Yes" << ln;
            return 0;
        }
    }
    cout << "No" << ln;
}

