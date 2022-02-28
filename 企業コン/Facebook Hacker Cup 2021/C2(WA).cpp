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

int solve(){
    int n, K; cin >> n >> K;
    vector<int> A(n); rep(i, n)cin >> A[i];

    vector<vector<pii>> g(n); //to, index
    vector<pii> E(n-1);
    rep(i, n-1){
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
        E[i] = {a, b};
    }
    if(n == 1 or K == 0)return A[0];

    vector<pair<int, vector<int>>> cand; //スコア、使った辺
    vector<int> edge; cand.emplace_back(A[0], edge); //根にトンネルを掘るケース
    //根から葉まで探索し、経路候補を列挙する
    auto dfs1 = [&](auto dfs1, int v, int p, int score, vector<int> edge) -> void{
        score += A[v];

        //葉に到着
        if(v != 0 and g[v].size() == 1){
            cand.emplace_back(score, edge);
            return;
        }

        for(auto [to, idx]:g[v]){
            if(to == p)continue;
            edge.emplace_back(idx); //通る辺番号を記録する
            dfs1(dfs1, to, v, score, edge);
            edge.pop_back();
        }
    };
    dfs1(dfs1, 0, -1, 0, edge);

    //往路と復路を全探索
    int res = -1;
    vector<int> used(n-1); //辺の使用済みフラグ
    vector<int> used_v(n); //頂点の使用済みフラグ

    //根を決めたときの往路、復路以外の最高スコアとパスを記録
    int max_p; vector<int> route;
    auto dfs2 = [&](auto dfs2, int v, int p, int score, vector<int> edge) -> void{
        if(!used_v[v])score += A[v]; //初回通過時のみ得点する

        bool leaf = true;
        for(auto [to, idx]:g[v]){
            if(to == p or used[idx])continue;
            edge.emplace_back(idx);
            dfs2(dfs2, to, v, score, edge);
            edge.pop_back();
            leaf = false;
        }
        if(leaf){
            if(chmax(max_p, score)){
                route = edge;
            }
        }
    };

    int siz = cand.size();
    rep(i, siz-1)rept(j, i+1, siz){
        vector<int> &E1 = cand[i].second;
        vector<int> &E2 = cand[j].second;
        used_v.assign(n, false);

        bool ok = true;
        //使用する辺に重複があっては駄目
        for(auto& e:E1){
            if(find(all(E2), e) != E2.end()){
                ok = false;
                break;
            }
        }
        if(!ok)continue;
        for(auto& e:E1){
            used[e] = true;
            used_v[E[e].first] = used_v[E[e].second] = true;
        }
        for(auto& e:E2){
            used[e] = true;
            used_v[E[e].first] = used_v[E[e].second] = true;
        }

        //残りのパスを貪欲に選択
        int tmp_score = cand[i].first + cand[j].first - A[0];
        rep(k, K-1){
            max_p = 0;
            route.clear();
            rep(s, n)if(!used_v[s]){ //使用済みの頂点を始点にする必要はない
                dfs2(dfs2, s, -1, 0, edge);
            }
            tmp_score += max_p;
            fore(idx, route){
                used[idx] = true;
                used_v[E[idx].first] = used_v[E[idx].second] = true;
            }
        }
        chmax(res, tmp_score);
        used.assign(n-1, false);
    }
    return res;
}

int main(){
    int T; cin >> T;

    vector<int> ans(T);
    rep(test, T){
        ans[test] = solve();
        //debug(test, ans[test]);
    }

    rep(i, T){
            cout << "Case #" << i+1 << ": " << ans[i]<< ln;
    }
}

