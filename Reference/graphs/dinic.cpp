#define MAXN 10100
#define INF 2000000000

struct Edge {
    int to;
    int flow;
    int cap;
    int rev;
    int id;
};

vector<Edge> g[MAXN];
int dist[MAXN], ptr[MAXN], ans[MAXN], src, sink;

void add_edge(int from, int to, int cap, int id) {
    Edge a = { to, 0, cap, (int)g[to].size(), id };
    Edge b = { from, 0, cap, (int)g[from].size(), -id };
    g[from].push_back(a);
    g[to].push_back(b);
}

bool BFS() {
    fill(dist, dist + MAXN, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (Edge e : g[u]) {
            int v = e.to;
            if (dist[v] < 0 && e.flow < e.cap) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[sink] >= 0;
}

int DFS(int u, int flow) {
    if (u == sink) return flow;

    for (int &i = ptr[u]; i < g[u].size(); i++) {
        Edge &e = g[u][i];
        if (e.cap > e.flow) {
            int v = e.to;
            if (dist[v] == dist[u] + 1) {
                int tmp_flow = DFS(v, min(flow, e.cap - e.flow));
                if (tmp_flow > 0) {
                    e.flow += tmp_flow;
                    g[v][e.rev].flow -= tmp_flow;
                    return tmp_flow;
                }
            }
        }
    }

    return 0;
}

int dinic(int s, int t) {
    src = s;
    sink = t;
    int max_flow = 0;

    while (BFS()) {
        fill(ptr, ptr + MAXN, 0);                                           
        while (int flow = DFS(src, INF)) max_flow += flow;
    }

    return max_flow;
}