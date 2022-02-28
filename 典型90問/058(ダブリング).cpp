#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
using vll = vector<long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
constexpr long long INF = 1000000000 + 100;
constexpr long long LINF = 1000000000000000000 + 100;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T> struct Doubling{
    const int MAX_K = 65;
    int N; //要素数
    vector<vector<T>> D; //D[k][i]:i番目の要素から2^k先の要素

    Doubling(int n): D(MAX_K) { //N:要素数
        N = n;
        for(int i=0; i<MAX_K; i++){
            D[i].resize(N);
        }
    }

    void init(vector<T>& A){ //A:i番目の要素から1つ先の要素
        for(int i=0; i<N; i++){
            D[0][i] = A[i];
        }
        for(int k=0; k<MAX_K-1; k++){
            for(int i=0; i<N; i++){
                D[k+1][i] = D[k][D[k][i]];
            }
        }
    }

    //要素startのK個先の要素を返す
    ll get(ll K, int start=0){
        int now = start;
        for(int k=0; K>0; k++){
            if(K&1)now = D[k][now];
            K >>= 1;
        }
        return now;
    }
};

const int NUM = 100000;

int calc(int n){
    int num = n;
    while(num){
        n += num%10;
        num /= 10;
    }
    return n % NUM;
}

int main(){
    ll N, K; cin >> N >> K;

    Doubling<int> d(NUM);
    vector<int> A(NUM);
    rep(i, A.size())A[i] = calc(i);
    d.init(A);
    cout << d.get(K, N) << ln;
}
