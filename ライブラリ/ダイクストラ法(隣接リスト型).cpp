using graph = vector<vector<pair<int, ll>>>;
vector<ll> Dijkstra(graph &G, int s = 0){
    int n = (int)G.size();

    vector<ll> dist(n, LLINF); dist[s] = 0;
    min_priority_queue<pair<ll, int>> que; que.push({0, 0});
    while(que.size()){
        auto [d, v] = que.top(); que.pop();
        if(d > dist[v]) continue;
        for(auto [nv, cost] : G[v]){
            ll nd = dist[v] + cost;
            if(nd < dist[nv]){
                dist[nv] = nd;
                que.push({dist[nv], nv});
            }
        }
    }

    return dist;
}