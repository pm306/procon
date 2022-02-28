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
deque
*/

const string error = "ERROR";

int main(){
    int N; string S; cin >> N >> S;

    deque<int> que;
    rep(i, N){
        int c = S[i];
        if(c=='L')que.push_front(i+1);
        if(c=='R')que.push_back(i+1);
        if(c=='A' or c=='B' or c=='C'){
            int num = c - 'A' + 1;
            if(que.size()<num)cout << error << ln;
            else{
                vector<int> tmp;
                rep(i, num){
                    tmp.push_back(que.front());
                    que.pop_front();
                }
                cout << tmp.back() << ln;
                tmp.pop_back();
                while(tmp.size()){
                    que.push_front(tmp.back());
                    tmp.pop_back();
                }
            }
        }
        if(c=='D' or c=='E' or c=='F'){
            int num = c - 'D' + 1;
            if(que.size()<num)cout << error << ln;
            else{
                vector<int> tmp;
                rep(i, num){
                    tmp.push_back(que.back());
                    que.pop_back();
                }
                cout << tmp.back() << ln;
                tmp.pop_back();
                while(tmp.size()){
                    que.push_back(tmp.back());
                    tmp.pop_back();
                }
            }
        }
    }
}
