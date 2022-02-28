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
半分全列挙
品物を2グループに分け、それぞれ選んだ個数ごとに全列挙する
→グループ1を選んだ個数ごとに総なめして、対応する個数のグループ2の答えの数を二分探索で求める
*/

int main(){
    ll N, K, P; cin >> N >> K >> P;
    vector<ll> A1, A2;
    rep(i, N){
        ll a; cin >> a;
        if(i&1)A1.push_back(a);
        else A2.push_back(a);
    }
    //mae[i]:=A1からi個選んだ値段の組み合わせ
    //ato[i]:=A2からi個選んだ値段の組み合わせ
    vector<vector<ll>> mae(22), ato(22);

    //全列挙
    auto dfs = [&](auto& self, int n, int k, ll sum, auto& A, bool isMae)->void{
        if(k > 20)return;
        if(n == A.size()){
            if(isMae)mae[k].push_back(sum);
            else ato[k].push_back(sum);
            return;
        }

        self(self, n+1, k+1, sum + A[n], A, isMae);
        self(self, n+1, k, sum, A, isMae);
    };
    dfs(dfs, 0, 0, 0, A1, true);
    dfs(dfs, 0, 0, 0, A2, false);

    for(int i=0; i<22; i++){
        mae[i].push_back(LINF);
        ato[i].push_back(LINF);
        sort(all(mae[i]));
        sort(all(ato[i]));
    }

    ll res = 0;

    for(int i=0; i<=A1.size(); i++){
        int j=K-i;
        if(j > A2.size() or (int)ato[j].size() == 0)continue;
        for(int k=0; k<mae[i].size(); k++){
            ll border = P - mae[i][k];
            ll tmp = upper_bound(all(ato[j]), border) - ato[j].begin();
            res += tmp;
        }
    }
    cout << res << ln;
}
