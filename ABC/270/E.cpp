#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
struct fast_ios { fast_ios() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); cerr << fixed << setprecision(7); }; } fast_ios_;
//////////////////////////////////////////////////////////////////////////////////////////////////]


int main(){
    ll N, K; cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    //各数が何回出現したか
    map<ll, ll> cnt;
    for(auto a:A)cnt[a]++;

    vector<ll> numbers = A;
    sort(all(numbers));
    UNIQUE(numbers);

    //eat:食べる回数, height=今見てるフェーズの高さ
    ll eat = K, height = 0, nokori = 0;
    //nokori:=残ったリンゴ入りかごの数
    for(auto a:A)if(a)nokori++;
    //フェーズ毎に状態を更新する
    for(auto n:numbers)if(n!=0){ //n:今回の高さ
        int bef_height = height; //前回の高さ

        height = n - height;
        ll cur_eat = nokori * height; //今回食べ切ろうとしてる数
        debug(eat, cur_eat);
        //全部食べ切れて次に行く
        if(eat > cur_eat){
            eat -= cur_eat; //食事カウントを減らす
            height = n; //最後に見た高さを更新
            nokori -= cnt[n]; //残りの箱の数を更新
        }
        //食べきれない
        else{
            ll roop = eat / nokori;  //周回できる数
            debug(eat, cnt[n], roop);
            ll simyu_cnt = eat % nokori; //余り
            debug(simyu_cnt, eat, nokori);
            // 全体を食べる回数はheight(前回の高さ)+roop
            ll zentai_roop = bef_height + roop;
            debug(bef_height, roop, zentai_roop); //おかしい。2になるはず

            for(auto&a:A) a = max(0ll, a-zentai_roop); //全体を食べる
            //シミュレーション
            int cnt = 0;
            rep(i, N){
                if(cnt == simyu_cnt)break;
                if(A[i]){
                    cnt++;
                    A[i]--;
                }
            }
            for(auto a:A) cout << a << " "; 
            cout << endl;
            exit(0);
        }
    }
}

