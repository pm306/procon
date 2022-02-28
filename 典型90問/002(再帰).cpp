#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
辞書順全列挙＝再帰全探索
bit全探索したくねえ～
*/

int N;
bool check(string& s){
    int stack = 0;
    for(auto& a:s){
        if(a=='(')stack++;
        else stack--;
        if(stack<0)return false;
    }
    return stack == 0;
}

void create_kakko(string s, vector<string>& ans){
    if(s.size()==N){
        if(check(s))ans.push_back(s);
        return;
    }
    create_kakko(s + "(", ans);
    create_kakko(s + ")", ans);
}

int main(){
    cin >> N;
    vector<string> ans;
    create_kakko("", ans);
    for(auto& s:ans)cout << s << ln;
}
