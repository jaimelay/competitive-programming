// Complexity: O(m * log(n))
void dijkstraSparse(int s){
    vector<int> dist(n, INF), parent(n);

    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({ 0, s });

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto e : g[u]) {
            int v = e.first;
            int w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }
}

// Complexity: O(n^2 + m)
void dijkstraDense(int s) {
    vector<int> dist(n, INF);
    vector<vector<int>> parent(n);
    vector<bool> vis(n, false);

    dist[s] = 0;
    parent[s] = { -1 };

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) {
            break;
        }

        vis[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (g[u][v] == 0) {
                continue;
            }

            int w = g[u][v];

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v].clear();
                parent[v].push_back(u);
            } else if (dist[u] + w == dist[v]) {
                parent[v].push_back(u);
            }
        } 
    }
}