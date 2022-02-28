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

void MergeSort(vector<int> &a, int l, int r){
    if(r - l == 1)return;

    //分割統治法
    int mid = (l + r) / 2;
    MergeSort(a, l, mid);
    MergeSort(a, mid, r);

    vector<int> buf;
    for(int i=l; i<mid; i++)buf.emplace_back(a[i]);
    for(int i=r-1; i>=mid; i--)buf.emplace_back(a[i]);
    //merge
    int idx_l = 0, idx_r = (int)buf.size() - 1;
    for(int i=l; i<r; i++){
        a[i] = buf[idx_l] <= buf[idx_r] ? buf[idx_l++] : buf[idx_r--];
    }

}

int main(){
    vector<int> A{4,7,11,6,3,8,1,5};
    fore(a, A)cout << a << " ";cout << ln;
    MergeSort(A, 0, A.size());
    fore(a, A)cout << a << " ";cout << ln;
}

