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

int N, M, Q;
int A[101010], B[101010], S[101010], T[101010];
vector<pair<int, int>> E[101010]; //隣接リスト {出発時間, 辺番号}
int dp[101010][20]; //dp[edge][p]:=辺edgeを最後に使い、2^p回バスに乗った時に最後に使った辺の番号

//頂点posに時間timeにいるときに、次に使われる辺の番号を返す。なければMを返す
int getNextIndex(int pos, int time){
    auto it = lower_bound(all(E[pos]), make_pair(time, -1));
    if(it == E[pos].end())return M;
    return it->second;
}

int main(){
    cin >> N >> M >> Q;
    rep(i, M){
        cin >> A[i] >> B[i] >> S[i] >> T[i]; A[i]--, B[i]--;
        E[A[i]].emplace_back(S[i], i);
    }
    rep(i, N)sort(all(E[i]));

    //ダブリングテーブルの作成
    rep(edge, M)dp[edge][0] = getNextIndex(B[edge], T[edge]);
    rep(p, 20)dp[M][p] = M;
    rept(p, 1, 20)rep(edge, M)dp[edge][p] = dp[dp[edge][p-1]][p-1];

    vector<pair<int, int>> ans;
    rep(_, Q){
        int X, Y, Z; cin >> X >> Y >> Z; Y--;

        int nearest = getNextIndex(Y, X);
        if(nearest == M)ans.emplace_back(Y, -1); //乗るバスがない
        else if(Z <= S[nearest])ans.emplace_back(Y, -1); //最初に乗れるバスより先に移動終了
        else if(S[nearest] < Z and Z <= T[nearest])ans.emplace_back(A[nearest], B[nearest]); //1本目のバスに乗っている

        //1本以上のバスに乗って頂点を移動したケース
        else{
            int curtime = T[nearest];
            int curedge = nearest;

            rrep(p, 20){
                int nxt = dp[curedge][p];
                if(nxt == M)continue;
                if(T[nxt] < Z){
                    curtime = T[nxt];
                    curedge = nxt;
                }
            }

            nearest = getNextIndex(B[curedge], curtime);
            if(nearest == M or Z <= S[nearest])ans.emplace_back(B[curedge], -1); //移動先がない or あるが間に合わない
            else ans.emplace_back(A[nearest], B[nearest]); //最後のバスに乗っている
        }

    }

    for(auto [a, b]:ans){
        cout << a + 1;
        if(b != -1)cout << " " << b + 1;
        cout << ln;
    }
}

