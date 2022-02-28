#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
#define all(v) v.begin( ), v.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n); i>=0; i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/*
畳の敷き詰め方を数え上げる

H*w<=16、と非常に小さいので3^16の全探索が間に合う　※勘違いしてた
配列は1次元で持てる(i,j) <-> (i*W+j)
条件式の「今いるマスが一番右か」「右or下のマスが未使用か」をちゃんとチェックする
*/


int main(){
    int H, W, A, B; cin >> H >> W >> A >> B;

    //次の未使用マスを調べる
    auto getNext = [&](int idx, vector<int>& used){
        return find(used.begin() + idx, used.end(), false) - used.begin();
    };

    //idx:現在位置, cnt,長方形を敷き詰めた枚数, used,敷き詰めフラグ
    auto dfs = [&](auto&& self, int idx, int cnt, vector<int> used) -> int{
        if(idx >= H*W-1){
            if(cnt == A){
                return 1;
            }else{
                return 0;
            }
        }
        used[idx] = true;
        int res = 0;
        //敷かない
        res += self(self, getNext(idx, used), cnt, used);
        //右に敷く
        if((idx+1) % W != 0 and used[idx+1] == false){
            used[idx+1] = true;
            res += self(self, getNext(idx, used), cnt+1, used);
            used[idx+1] = false;
        }
        //下に敷く
        if(idx+W < H*W and used[idx+W] == false){
            used[idx+W] = true;
            res += self(self, getNext(idx, used), cnt+1, used);
        }
        return res;
    };
    vector<int> used(H*W);
    cout << dfs(dfs, 0, 0, used) << ln;
}
