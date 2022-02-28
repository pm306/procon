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

const string NO = "UNSOLVABLE";

int main(){
    string S, T, U; cin >> S >> T >> U;

    //文字列を添え字に変換
    map<char, string> mp; vector<char> memo; int index = 0;
    auto func = [&](string s)->string{
        string res = "";
        for(auto a: s){
            //初出時にメモ
            if(whole(find, memo, a) == memo.end()){
                memo.push_back(a);
                mp[a] = to_string(index);
                index++;
            }
            res += mp[a];
        }
        return res;
    };
    S = func(S); T = func(T); U = func(U);

    if(index>10){
        cout << NO << ln;
        return 0;
    }

    vector<int> NP; //sorted
    rep(i, 10)NP.push_back(i);

    //インデックス文字列を対応する数値に変換。先頭がゼロになったら負を返す
    auto conv = [&](string s) ->ll{
        ll res = 0, first = -1;
        for(auto a:s){
            ll num = NP[a-'0'];
            if(first==-1)first = num;
            res = res * 10 + num;
        }
        if(first==0)return -LINF;
        return res;

    };
    do {
        ll a = conv(S), b = conv(T), c = conv(U);
        if(a+b==c){
            cout << a << ln;
            cout << b << ln;
            cout << c << ln;
            return 0;
        }
    } while (whole(next_permutation, NP));
    cout << NO << ln;
}
