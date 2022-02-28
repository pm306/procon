#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr char ln =  '\n';
constexpr long long INF = 1LL<<60;
constexpr double EPS = 1e-9;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
#define rrep(i, n) for(int i=(n)-1; i>=0; i--)
#define fore(i,a) for(auto &i:a)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void QuickSort(vector<int> &a, int l, int r){
    if(r - l <= 1)return;

    int pivot_idx = (l + r)/ 2; //適当に決める
    int pivot = a[pivot_idx];
    swap(a[pivot_idx], a[r-1]);//右端に持ってくる

    int i = l; // i := 左詰めされた基準値未満の右端
    for(int j=l; j<r-1; j++){
        if(a[j]<pivot)swap(a[i++], a[j]);
    }
    swap(a[i], a[r-1]);

    QuickSort(a, l, i);//基準値未満を再帰的に解く
    QuickSort(a, i+1, r);//基準値以上
}

int main(){
    vector<int> a{8,7,6,5,4,3,2,1};
    QuickSort(a, 0, a.size());
    fore(b,a)cout << b << ln;
}

