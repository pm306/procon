#include <bits/stdc++.h>
using namespace std;

int N; //頂点の数
vector<vector<int>> G; //グラフ
vector<int> h; //入次数
vector<int> l_depth; //最大経路長
vector<int> ans; //トポロジカルソート結果を格納

void input(){
  int n;
  cin>>n;
  vector<vector<int>> IDs(n, vector<int>(n, -1));
  N = n*(n-1)/2;
  G.resize(N);
  h.resize(N, 0);
  l_depth.resize(N, -1);

  int id = 0;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      IDs[i][j] = id;
      IDs[j][i] = id;
      id++;
    }
  }

  int t, bufid, vsid;
  for(int i=0; i<n; i++){
    bufid = -1;
    for(int j=0; j<n-1; j++){
      cin>>t;t--;
      vsid = IDs[i][t];

      if(bufid != -1){
        G[bufid].push_back(vsid);
        h[vsid]++;
      }

      bufid = vsid;
    }
  }
}

void topoBFS(){
  queue<int> unchecked;
  for(int i=0; i<N; i++){
    if(h[i]==0){
      unchecked.push(i); //入次数が0の頂点をキューに入れる
      l_depth[i] = 0; //そのような頂点は深さが0
    }
  }
  while(!unchecked.empty()){
    int current = unchecked.front();
    unchecked.pop();
    ans.push_back(current); //キューから取り出したらすぐソート後のリストに加える

    for(int next: G[current]){ //「行ける」頂点について
      h[next]--; //入次数を減らす
      l_depth[next] = max(l_depth[next], l_depth[current]+1); //最長経路
      if(h[next]==0){ //入次数0になったらキューに追加
        unchecked.push(next);
      }
    }
  }
}

int main(){
  input();

  topoBFS();

  for(auto a: ans)cout << a << " "; cout << endl;
  for(auto d: l_depth)cout << d << " "; cout << endl;

  bool isDAG = ans.size()==N;
  if(isDAG){
    int l_max = *max_element(l_depth.begin(), l_depth.end()); //l_depthの最大値をとる
    cout<<l_max+1<<endl;
  }else{
    cout<<-1<<endl;
  }
}
