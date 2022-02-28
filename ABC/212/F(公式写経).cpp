#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pll = pair<ll, ll>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i, a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    int N, M, Q; cin >> N >> M >> Q;
    vector<int> A(M), B(M), S(M), T(M);
    vector<vector<pair<int, int>>> bus(N); //start_time, index
    rep(i, M){
        cin >> A[i] >> B[i] >> S[i] >> T[i]; A[i]--, B[i]--;
        bus[A[i]].emplace_back(S[i], i);
    }
    fore(b, bus)sort(all(b));

    vector table(20, vector<int>(M)); //ダブリングテーブル
    //init
    rep(i, M){
        auto it = lower_bound(all(bus[B[i]]), make_pair(T[i], -1));
        if(it == bus[B[i]].end())table[0][i] = i;
        else table[0][i] = it->second;
    }
    //create
    rept(i, 1, 20)rep(j, M){
        table[i][j] = table[i-1][table[i-1][j]];
    }

    vector<pair<int, int>> ans(Q);
    rep(i, Q){
        int X, Y, Z; cin >> X >> Y >> Z; Y--;
        auto it = lower_bound(all(bus[Y]), make_pair(X, -1));
        //時刻X以降のバスが存在しない
        if(it == bus[Y].end()){
            ans[i] = {Y, -1};
            continue;
        }
        int now = it->second;
        //時刻X以降のバスが存在するが、最初の出発時刻が時刻Z以降
        if(Z <= S[now]){
            ans[i] = {Y, -1};
            continue;
        }
        //時刻X以降のバスに乗り、乗車中に時刻Zを迎える
        if(Z <= T[now]){
            ans[i] = {A[now], B[now]};
            continue;
        }

        rrep(i, 20){
            int next = table[i][now];
            if(T[next] < Z) now = next;
        }
        it = lower_bound(all(bus[B[now]]), make_pair(T[now], -1));
        //バスが存在しない
        if(it == bus[B[now]].end()){
            ans[i] = {B[now], -1};
            continue;
        }
        int next = it->second;
        //バスが存在するが、乗れない
        if(Z <= S[next]){
            ans[i] = {B[now], -1};
            continue;
        }
        //バスに乗れる
        ans[i] = {A[next], B[next]};
    }

    for(auto [a, b]: ans){
        cout << a + 1;
        if(b != -1)cout << " " << b + 1;
        cout << ln;
    }
}

