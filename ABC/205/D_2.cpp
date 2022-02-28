#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
using vll = vector<long long>;
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

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
    int N, Q; cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }
    A.push_back(LINF*5);

    //min_priority_queue<pll> que; //num, query
    vector<pll> v;
    rep(i, Q){
        ll a; cin >> a;
        //que.push({a, i});
        v.emplace_back(a, i);
    }
    sort(v.begin(), v.end());

    vector<ll> ans(Q);
    ll rui = A[0] - 1, idx = 0;
    /*while(que.size())*/for(auto [k, i]: v){
        //auto p = que.top(); que.pop();
        //ll k = p.first, i = p.second;
        while(rui < k){
            rui += A[idx+1] - A[idx] - 1;
            idx++;
        }
        ll res = A[idx] + k - rui - 1;
        ans[i] = res;
    }
    for(auto a:ans)cout << a << ln;

}
