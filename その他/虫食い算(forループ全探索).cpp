#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
  a 3 c
x   b 2
-------
□ 2 □ □
□ □ 1
-------
□ □ □ □
*/

int main(){
    for(int a=1; a<=9; a++){
        for(int b=1; b<=9; b++){
            for(int c=1; c<=9; c++){
                int ue = a * 100 + 3 * 10 + b;

                //一段目
                int seki1 = ue * 2;
                if(seki1 < 1000)continue; //4桁でないとダメ
                if(seki1 / 100 % 10 != 2)continue; //100の位が2

                //二段目
                int seki2 = ue * c;
                if(seki2 >= 1000)continue; //3桁でないとダメ
                if(seki2 % 10 != 1)continue; //1の位が1

                //積
                int shita = c * 10 + 2;
                int seki = ue * shita;
                if(seki >= 10000)continue; //4桁でないとダメ

                cout << ue << " x " << shita << " = " << seki << ln;
            }
        }
    }
}

