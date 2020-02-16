#define MAXN 100009

const int INF = 0x3f3f3f3f;

int dist[MAXN];
vector<pair<int, int>> g[MAXN];

int dijkstra(int src, int dest){
    for(int i = 1; i <= n; i++) dist[i] = INF;

    dist[src] = 0;
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
    
    return dist[dest];
}