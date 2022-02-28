#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
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


//ヒープの実装
//デフォルトでは昇順
template<class T>
struct Heap{
	vector<T> tree; //二分木
	bool is_asc; //ソート順。true:昇順、false:降順

	//コンストラクタ。デフォでは昇順ソート
	Heap(bool is_asc_ = true){is_asc = is_asc_;};

	//ヒープの大きさを返す
	int length(){return (int)tree.size();}

	//木の高さを返す
	int height(){
		int n = tree.size();
		int ret = 0;
		while(n){
			n /= 2;
			ret++;
		}
		return ret;
	}

	//２つの値が順序通りに並んでいるかを返す
	//昇順：a <= bならtrue
	//降順：a >= bならtrue
	bool compare(T a, T b){ return is_asc ? a <= b : a >= b;}

	//要素の挿入
	void push(T n){
		//木の末尾にnを追加する
		tree.push_back(n);
		//親子関係を整頓する
		int k = length() - 1;
		while(k > 0){
			int p = (k - 1) / 2;
			//親子関係が正しくなければ両者を交換し、現在のノードを更新する
			if(!compare(tree[p], tree[k])){
				swap(tree[k], tree[p]);
				k = p;
			}
			//正しければループを抜ける
			else{
				break;
			}
		}
	}

	//先頭要素の削除
	void erase(){
		if(length() == 0)return; //空なら何もしない

		//先頭要素を削除し、先頭に最後尾の値を挿入する。
		//実装としては、最後尾の値を根に代入し、最後尾を削除する
		tree[0] = tree.back();
		tree.pop_back();

		int k = 0; //今見てるノード
		//親子関係を整頓する
		while(k*2+1 < length()){
			int l = k*2+1, r=k*2+2;
			int c = l;
			if(r < length() and !compare(tree[l], tree[r])){
				c = r;
			}
			if(!compare(tree[k], tree[c])){
				swap(tree[k], tree[c]);
				k = c;
			}
			else{
				break;
			}
		}
	}

	//先頭の要素を取得する(削除しない)
	T top(){return tree[0];}

	//先頭の要素を取り出す(ヒープから削除し、その値を返す)
	T pop(){
		T ret = top();
		erase();
		return ret;
	}

	//デバッグ
	void print(){
		for(auto & v : tree){
			cout << v << " ";
		}
		cout << endl;
	}
};

int main(){
	Heap<int> que(false);
	while(true){
		string order; cin >> order;
		if(order == "end")break;

		if(order == "insert"){
			int x; cin >> x;
			que.push(x);
		}
		if(order == "extract"){
			cout << que.pop() << ln;
		}
	}
}

