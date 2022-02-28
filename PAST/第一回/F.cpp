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
・大文字と小文字の混ざったソート
・そのままsort関数を使うと正しくソートされない
・一旦大文字に揃えてから出力時に復元
*/

int main(){
    string S; cin >> S;
    vector<string> V;

    bool fg = false; string t = "";
    fore(s,S){
        if(s >= 'A' and s <= 'Z'){
            t += s;
            if(!fg){
                fg = true;
            }
            else{
                fg = false;
                V.push_back(t);
                t = "";
            }
        }
        else{
            t += (s - 32);
        }
    }
    sort(all(V));
    fore(v,V){
        rep(i, v.size()){
            if(i==0 or i==v.size()-1)cout << v[i];
            else cout << (char)(v[i] + 32);
        }
    }
    cout << ln;
}
