#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr int INF = INT_MAX / 2;
constexpr long long LLINF = 3e18;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i, a) for(auto &i:a)
template <class T1, class T2> inline bool chmax(T1& a, T2 b) { if (a < b) { a = b; return true; } return false; }
template <class T1, class T2> inline bool chmin(T1& a, T2 b) { if (a > b) { a = b; return true; } return false; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T> inline void UNIQUE(vector<T>& v) { v.erase(unique(v.begin(), v.end()), v.end()); }
inline int popcount(ll x) { return __builtin_popcountll(x); }
inline ll CEIL(ll a, ll b){return (a+b-1) / b;}
const string YesNo[2] = {"No", "Yes"};
inline void Yes(bool t = true) { cout << YesNo[t] << "\n"; }
template <class T> inline void drop(T x) { cout << x << "\n"; exit(0); }

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



int main(){
    int N; string S; cin >> N >> S;

    vector<int> par(N+1, -1), child(N+1, -1);
    for(int i=1; i<=N; i++){
        char order = S[i-1];
        if(i == 1){
            if(order == 'L'){
                child[i] = 0;
                par[0] = i;
            }
            else{
                child[0] = i;
                par[i] = 0;
            }
        }
        else{
            if(order == 'L'){
                int tmp_par = par[i-1];
                child[i] = i-1;
                par[i-1] = i;
                if(tmp_par != -1){
                    par[i] = tmp_par;
                    child[tmp_par] = i;
                }
            }
            else{
                int tmp_chi = child[i-1];
                par[i] = i-1;
                child[i-1] = i;
                if(tmp_chi != -1){
                    child[i] = tmp_chi;
                    par[tmp_chi] = i;
                }
            }
        }
    }
    int cur = -1;
    rep(i, N+1)if(par[i] == -1){
        cur = i;
        break;
    }
    while(true){
        cout << cur << " ";
        cur = child[cur];
        if(cur == -1){
            break;
        }
    }
    cout << ln;
}