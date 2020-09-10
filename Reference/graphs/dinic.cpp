// Complexity:
// Dinic - O(V^2 * E)
// Bipartite Graph or Unit Flow - O(sqrt(V) * E)
// Small flow - O(F * (V + E))

struct Edge {
    int to;
    int flow;
    int cap;
    int rev;
    int id;

    Edge(int to, int flow, int cap, int rev, int id = -1) :
        to(to), flow(flow), cap(cap), rev(rev), id(id) {}
};

vector<Edge> g[MAXN];
int dist[MAXN], ptr[MAXN];

void addEdge(int from, int to, int cap, int id = 0) {
    g[from].push_back(Edge(to, 0, cap, g[to].size(), id));
    g[to].push_back(Edge(from, 0, 0, g[from].size() - 1, -id));
}

bool dinicBFS(int s, int t) {
    memset(dist, -1, sizeof(dist));
    queue<int> q;

    dist[s] = 0;
    q.push(s);

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

    return dist[t] >= 0;
}

int dinicDFS(int s, int t, int flow) {
    if (s == t) {
        return flow;
    }

    for (int &i = ptr[s]; i < int(g[s].size()); i++) {
        Edge &e = g[s][i];

        if (e.cap > e.flow) {
            int v = e.to;

            if (dist[v] == dist[s] + 1) {
                int tmp_flow = dinicDFS(v, t, min(flow, e.cap - e.flow));

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
    int max_flow = 0;

    while (dinicBFS(s, t)) {
        memset(ptr, 0, sizeof(ptr));

        while (int flow = dinicDFS(s, t, INF)) {
            max_flow += flow;
        }
    }

    return max_flow;
}

bool cut[MAXN];

void minCutDFS(int u) {
    cut[u] = 1;

    for (auto x : g[u]) {
        if (x.cap > x.flow && !cut[x.to]) {
            minCutDFS(x.to);
        }
    }
}

vector<int> findMinCut() {
    vector<int> idx_edges;

    for (int i = 1; i <= n; i++) {
        for (Edge e : g[i]) {
            if (cut[i] && !cut[e.to]) {
                idx_edges.push_back(e.id);
            }
        }
    }
    return idx_edges;
}