#define MAXN 100009

const int INF = 0x3f3f3f3f;

int dist[MAXN];
vector<pair<int, int>> G[MAXN];

int dijkstra(int src, int dest){
    for(int i = 1; i <= n; i++) dist[i] = INF;

    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({ 0, src });

    while(!pq.empty()){
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d > dist[v]) continue;
        for(auto edge : G[v]){
            int u = edge.first;
            int w = edge.second;
            if(dist[u] > dist[v] + w){
                dist[u] = dist[v] + w;
                pq.push({ dist[u], u });
            }
        }
    }
    
    return dist[dest];
}