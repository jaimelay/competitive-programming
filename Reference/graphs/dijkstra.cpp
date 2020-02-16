#define MAXN 100009

const int INF = 0x3f3f3f3f;

int dist[MAXN], parent[MAXN];
vector<pair<int, int>> g[MAXN];

// Complexity: O(m * log(n))
void dijkstra_sparse(int s){
    for(int i = 0; i < n; i++) dist[i] = INF;

    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({ 0, src });

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto e : g[u]){
            int v = e.first;
            int w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
}

// Complexity: O(n^2 + m)
void dijkstra_dense(int s) {
    for(int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    vector<bool> vis(n, false);

    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (dist[u] == INF) break;

        vis[u] = true;
        for (auto edge : g[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
}