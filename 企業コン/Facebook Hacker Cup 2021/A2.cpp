#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i, a) for(auto &i:a)
template <class T1, class T2> inline bool chmax(T1& a, T2 b) { if (a < b) { a = b; return true; } return false; }
template <class T1, class T2> inline bool chmin(T1& a, T2 b) { if (a > b) { a = b; return true; } return false; }

template <class T> inline void drop(T x) { cout << x << "\n"; exit(0); }
inline void print() { cout << "\n"; }
template <class T> inline void print(const vector<T>& v) { for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) { cout << " "; } cout << *it; } print(); }
template <class T, class... Args> inline void print(const T& x, const Args& ... args) { cout << x << " "; print(args...); }

#ifdef _DEBUG
template <class T1, class T2> ostream& operator<<(ostream& os, pair<T1, T2> p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <size_t N, class TUPLE> void debug_tuple(ostream& os, TUPLE _) { (void)os; (void)_; }
template <size_t N, class TUPLE, class T, class ...Args> void debug_tuple(ostream &os, TUPLE t) { os << (N == 0 ? "" : ", ") << get<N>(t); debug_tuple<N + 1, TUPLE, Args...>(os, t); }
template <class ...Args> ostream& operator<<(ostream& os, tuple<Args...> t) { os << "("; debug_tuple<0, tuple<Args...>, Args...>(os, t); return os << ")"; }
string debug_delim(int& i) { return i++ == 0 ? "" : ", "; }
#define debug_embrace(x) { int i = 0; os << "{";  { x } return os << "}"; }
template <class T> ostream& operator<<(ostream& os, vector<T> v) { debug_embrace( for (T e : v) { os << debug_delim(i) << e; } ) }
template <class T, size_t N> ostream& operator<<(ostream& os, array<T, N> a) { debug_embrace( for (T e : a) { os << debug_delim(i) << e; } ) }
template <class T, size_t N> enable_if_t<!is_same_v<char, remove_cv_t<T>>, ostream>& operator<<(ostream& os, T(&a)[N]) { debug_embrace( for (T e : a) { os << debug_delim(i) << e; } ) }
template <class Key> ostream& operator<<(ostream& os, set<Key> s) { debug_embrace( for (Key e : s) { os << debug_delim(i) << e; }) }
template <class Key, class T> ostream& operator<<(ostream& os, map<Key, T> mp) { debug_embrace( for (auto e : mp) { os << debug_delim(i) << e; }) }
template <class Key> ostream& operator<<(ostream& os, multiset<Key> s) { debug_embrace( for (Key e : s) { os << debug_delim(i) << e; }) }
template <class T> ostream& operator<<(ostream& os, queue<T> q) { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.front(); } ) }
template <class T> ostream& operator<<(ostream& os, deque<T> q) { debug_embrace( for (T e : q) { os << debug_delim(i) << e; } ) }
template <class T> ostream& operator<<(ostream& os, priority_queue<T> q) { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.top(); } ) }
template <class T> ostream& operator<<(ostream& os, priority_queue<T, vector<T>, greater<T>> q) { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.top(); } ) }
void debug_out() { cerr << endl; }
template <class T, class... Args> void debug_out(const T& x, const Args& ... args) { cerr << " " << x; debug_out(args...); }
#define debug(...) cerr << __LINE__ << " : [" << #__VA_ARGS__ << "] =", debug_out(__VA_ARGS__)
#else
#define debug(...)(void(0))
#endif
//////////////////////////////////////////////////////////////////////////////////////////////////



vector<ll> bfs(vector<vector<int>>& g, int s){
    int n = g.size();
    vector<ll> dist(n, INF); dist[s] = 0;
    queue<int> que; que.push(s);

    while(!que.empty()){
        int v = que.front(); que.pop();

        for(auto& nv: g[v]){
            if(dist[nv] == INF){
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }
    return dist;
}

ll solve(){
    string S; int K; cin >> S >> K;

    //文字の置換を有向グラフで表現
    vector<vector<int>> g(26);
    rep(i, K){
        string t; cin >> t;
        g[t[0]-'A'].push_back(t[1]-'A');
    }

    //cdist[s][t]文字sから文字tまでの最短置換距離
    vector cdist(26, vector<ll>(26, -1));
    rep(s, 26){
        auto dist = bfs(g, s);
        rep(t, 26)cdist[s][t] = dist[t];
    }

    ll res = INF;
    rep(to, 26){
        ll cnt = 0;
        for(auto s:S){
            int from = s - 'A';
            if(cdist[from][to] == INF){
                cnt = INF;
                break;
            }
            cnt += cdist[from][to];
        }
        chmin(res, cnt);
    }

    if(res == INF)res = -1;
    return res;
}

int main(){
    int T; cin >> T;

    vector<int> ans(T);
    rep(test, T){
        ans[test] = solve();
    }

    rep(i, T){
        cout << "Case #" << i+1 << ": " << ans[i] << ln;
    }
}
