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

int sgn(const double a) {
		return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
	}

	struct Point {
		//2次元ベクトルのクラス

		double x, y;
		Point(double _x, double _y) {
			x = _x, y = _y;
		}
		Point() {
			x = 0, y = 0;
		}

		Point operator+() const {
			return *this;
		}
		Point operator-() const {
			return{ -x, -y };
		}
		Point operator+ (const Point& b) const {
			return{ x + b.x, y + b.y };
		}
		Point operator- (const Point& b) const {
			return{ x - b.x, y - b.y };
		}
		Point operator* (const double b) const {
			return{ x * b, y * b };
		}
		Point operator/ (const double b) const {
			return{ x / b, y / b };
		}
		Point operator+= (const Point& b) {
			x += b.x, y += b.y;
			return *this;
		}
		Point operator-= (const Point& b) {
			x -= b.x, y -= b.y;
			return *this;
		}
		Point operator*= (const double b) {
			x *= b, y *= b;
			return *this;
		}
		Point operator/= (const double b) {
			x /= b, y /= b;
			return *this;
		}
		bool operator== (const Point& b) {
			return b.x == x && b.y == y;
		}

		double lengthSquare() const {
			return (x * x + y * y);
		}
		double length() const {
			return std::sqrt(lengthSquare());
		}
		double dot(const Point& b) const {
			return x * b.x + y * b.y;
		}
		double cross(const Point& b) const {
			//Generally, cross product is vector, but in 2D, cross product is also scalar.
			return x * b.y - y * b.x;
		}
		double distanceFrom(const Point& b) const {
			return std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
		}
		Point normalized() const {
			return{ x / length(), y / length() };
		}
		bool isZero() const {
			return sgn(x) == 0 && sgn(y) == 0;
		}
		//単位法線ベクトル
		Point normalUnitVector() const {
			return{ -normalized().y, normalized().x };
		}
		//(0, 0)中心にarg(弧度法)回転した座標
		Point rotation(double arg) const {
			double cs = cos(arg), sn = sin(arg);
			return Point(x * cs - y * sn, x * sn + y * cs);
		}
		//(0, 0)中心の円上に乗ってるとしたときの、偏角
		double angle() const {
			return atan2(y, x);
		}
	};

	inline Point operator*(double a, const Point& b) {
		return{ b.x * a, b.y * a };
	}

	template <class Char>
	inline std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const Point& v)
	{
		return os << Char('(') << v.x << Char(',') << v.y << Char(')');
	}

	template <class Char>
	inline std::basic_istream<Char>& operator >> (std::basic_istream<Char>& is, Point& v)
	{
		return is >> v.x >> v.y;
	}

	//幾何ライブラリにおいて、解なしのような状態の時に返される点の値
	const Point error_val = { 114514.0, -191981.0 };

	inline bool operator==(const Point& a, const Point& b) {
		return (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0);
	}

	inline bool operator!=(const Point& a, const Point& b) {
		return !(a == b);
	}

	//第一にx, 第二にyを小さい順にソートするためのオーバーロード
	inline bool operator<(const Point& a, const Point& b) {
		if (sgn(a.x - b.x) != 0)return sgn(a.x - b.x) < 0;
		else return sgn(a.y - b.y) < 0;
	}

/*
3点A, B, Cの位置関係を返す関数 A, Bがすべて異なった点であるのが前提
//ABから見てBCは左に曲がるのなら +1
//ABから見てBCは右に曲がるのなら -1
//ABC(CBA)の順番で一直線上に並ぶなら +2
//ACB(BCA)の順番で一直線上に並ぶなら 0
BAC(CAB)の順番で一直線上に並ぶなら -2
*/
int iSP(const Point& a, const Point& b, const Point& c) {
    int flg = sgn((b - a).cross(c - a));
    if (flg == 1) {
        return +1;
    }
    else if (flg == -1) {
        return -1;
    }
    else {
        //ABC(CBA)
        if (sgn((b - a).dot(c - b)) > 0)
            return +2;
        //BAC(CAB)
        else if (sgn((a - b).dot(c - a)) > 0)
            return -2;
        //ACB(BCA)　CがA or Bと一致しても、こっちに含まれる。
        else
            return 0;
    }
}

//角ABCが鋭角なら0、直角なら1、鈍角なら2を返す。
int angletype(const Point& a, const Point& b, const Point& c) {
    auto v = (a - b).dot(c - b);
    if (sgn(v) > 0)return 0;
    else if (sgn(v) == 0)return 1;
    else return 2;
}

int main(){
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    double moveX = bx, moveY = by; bx = by = 0; //Bを原点に移動
    ax -= moveX, cx -= moveX, ay -= moveY, cy -= moveY;

    Point A(ax, ay), B(bx, by), C(cx, cy);
    int angleABC = angletype(A, B, C);
    int angleACB = angletype(A, C, B);

    cout << fixed << setprecision(12);

    //パターン１
    if(angleABC == 2){
        cout << A.length() << ln;
    }
    //パターン2
    else if(angleABC == 0 and angleACB == 0){
        cout << abs(A.cross(C)) / C.length() << ln;
    }
    //パターン3
    else if(angleACB == 2){
        cout << A.distanceFrom(C) << ln;
    }
}

