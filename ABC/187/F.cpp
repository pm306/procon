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

/*
・隣接bit表現(?)。E[v]:=頂点vと隣接する頂点のbit集合。和演算で作る

・クリーク判定
頂点集合を1つの頂点とそれ以外の頂点(0個でも良い)に分割する
分割は引き算
それ以外の頂点集合がクリークor空集合　かつ　1つの頂点からそれ以外の頂点すべてに辺が伸びていればその頂点集合はクリーク

・最小クリーク数を知りたい
頂点集合を2分割する。部分集合の部分集合はO(3^n)で求まるとか。
chmin ( dp[元の頂点集合] , dp[分割集合1] + dp[分割集合2] )
集合が元からクリークなら↑の前処理でdp = 1になってるので更新が起きない
クリークでない場合、分割した2つの頂点集合の最小クリーク数を足し合わせたものを更新する
（クリークでないので、分割集合を独立に考えないといけない）
*/

int main(){
    int n, m; cin >> n >> m;
    vector<int> A(m), B(m);
    //自分が繋がっている辺のbit集合
    vector<int> E(n);

    rep(i, m){
        cin >> A[i] >> B[i]; A[i]--, B[i]--;
        E[A[i]] |= 1<<B[i]; //EのA[i]番目のB[i]番目のbitが立っている = A[i]とB[i]は繋がっている
        E[B[i]] |= 1<<A[i];
    }

    //集合sをいくつのクリークで実現できるか
    vector<int> dp(1<<n, 1<<30);
    dp[0] = 0;

    //集合bitがクリーク(完全グラフ)になっているかを調べる
    //頂点集合bitを(頂点v取り除いた頂点集合s) + (頂点v)に分けて、vからsの全頂点に辺が伸びているか調べる
    //計算量O(n^2n)
    for(int bit=1; bit<1<<n; bit++){
        for(int i=0; i<n; i++){
            //iビット目が立ってるか調べる
            if((bit&(1<<i)) == 0)continue;
            int target = bit - (1<<i);
            //クリークが作れるか調べる。
            //dp[target]がクリーク かつ vから伸びている点の頂点集合にtargetが完全に含まれている
            if(dp[target] <= 1 and (E[i] & target) == target){
                dp[bit] = 1;
            }
            //1つの分け方を調べれば十分
            break;
        }
    }

    //集合bitが何個のクリークで実現できるかを考える
    for(int bit=0; bit<1<<n; bit++){
        //bitの部分集合だけを抽出できる？
        for(int i=bit; i>0; i = (i-1) & bit){
            //bitをiとjの2つの集合に分ける
            //計算量O(3^n)
            int j = bit - i;
            chmin(dp[bit], dp[i] + dp[j]);
        }
    }
    cout << dp[(1<<n)-1] << ln;
}

