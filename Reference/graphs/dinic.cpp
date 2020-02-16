#define MAXN 10100
#define INF 0x3f3f3f3f

struct Edge {
    int to;
    int flow;
    int cap;
    int rev;
    int id;

    Edge () {}

    Edge (int to, int flow, int cap, int rev, int id) :
        to(to), flow(flow), cap(cap), rev(rev), id(id) {}
};

vector<Edge> g[MAXN];
int dist[MAXN], ptr[MAXN], ans[MAXN], src, sink;

void add_edge(int from, int to, int cap, int id) {
    g[from].push_back(Edge(to, 0, cap, g[to].size(), id));
    g[to].push_back(Edge(from, 0, 0, g[from].size() - 1, -id));
}

bool dinic_bfs() {
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

int dinic_dfs(int u, int flow) {
    if (u == sink) return flow;

    for (int &i = ptr[u]; i < g[u].size(); i++) {
        Edge &e = g[u][i];
        if (e.cap > e.flow) {
            int v = e.to;
            if (dist[v] == dist[u] + 1) {
                int tmp_flow = dinic_dfs(v, min(flow, e.cap - e.flow));
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

    while (dinic_bfs()) {
        fill(ptr, ptr + MAXN, 0);                                           
        while (int flow = dinic_dfs(src, INF)) max_flow += flow;
    }

    return max_flow;
}

bool cut[MAXN];
void mincut_dfs(int u) {
    cut[u] = 1;
    for (auto x : g[u]) {
        if (x.cap > x.flow && !cut[x.to]) {
            mincut_dfs(x.to);
        }
    }
}

vector<int> find_mincut() {
    vector<int> idx_edges;
    for (int i = 1; i <= n; i++) {
        for (Edges e : g[i]) {
            if (cut[i] && !cut[e.to]) {
                idx_edges.push_back(e.id);
            }
        }
    }
    return idx_edges;
}