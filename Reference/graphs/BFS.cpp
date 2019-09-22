vector<int> adj[n];
int dist[n];

void BFS(){
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(dist[v] == -1 || dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}