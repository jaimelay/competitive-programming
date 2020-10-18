int vis[MAXN], dist[MAXN], maior, end_point;
vector<int> g[MAXN];
stack<int> topoSort;

void topological_sort(int v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(!vis[u]) topological_sort(u);
    }
    topoSort.push(v);
}

void longest_path(int src){
    dist[src] = 0;
    maior = 0;
    while(!topoSort.empty()){
        int v = topoSort.top();
        topoSort.pop();
        if(dist[v] != -1){
            for(auto u : g[v]){
                dist[u] = max(dist[u], dist[v] + 1);
            }
        }
        maior = max(maior, dist[v]);
    }
    for(int i = 1; i <= n; i++){
        if(maior == dist[i]){
            end_point = i;
            break;
        }
    }
}