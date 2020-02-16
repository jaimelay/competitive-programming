#define MAXN 110
#define INF 0x3f3f3f3f

struct Edge {
    int to;
    int flow;
    long long cap;
    long long cost;
    int rev;

    Edge() {}

    Edge (int to, int flow, long long cap, long long cost, int rev) :
        to(to), flow(flow), cap(cap), cost(cost), rev(rev) {}
};

vector<Edge> g[MAXN];
long long dist[MAXN], phi[MAXN];
int n, m;
pair<int, int> parent[MAXN];

void add_edge(int from, int to, long long cap, long long cost) {
    g[from].push_back(Edge(to, 0, cap, cost, g[to].size()));
    g[to].push_back(Edge(from, 0, 0, -cost, g[from].size() - 1));
}

void mcmf_bellman_ford(int s) {
    fill(phi, phi + MAXN, INF);
    phi[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (Edge e : g[u]) {
                if (!e.cap) continue;
                int v = e.to;
                long long w = e.cost;
                phi[v] = min(phi[v], phi[u] + w);
            }
        }
    }
}

bool mcmf_dijkstra(int s, int t) {
    for (int i = 0; i < MAXN; i++) {
        dist[i] = INF;
        parent[i] = { -1, -1 };
    }

    dist[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > pq;
    pq.push({ 0, s });

    bool flag = false;
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (u == t) flag = true;

        if (d != dist[u]) continue;

        for (int i = 0; i < g[u].size(); i++) {
            Edge e = g[u][i];
            int v = e.to;

            if (e.cap - e.flow <= 0) continue;

            long long w = e.cost + phi[u] - phi[v];
            if (dist[v] > d + w) {
                dist[v] = d + w;
                parent[v] = { u, i };
                pq.push({ dist[v], v });
            }
        }
    }

	for (int i = 0; i < MAXN; i++) {
		if (phi[i] < INF and dist[i] < INF) {
			phi[i] += dist[i];
        }
    }

    return flag;
}

pair<long long, long long> mcmf(int s, int t) {
    long long min_cost = 0, max_flow = 0;
    mcmf_bellman_ford(s);

    while (mcmf_dijkstra(s, t)) {
        long long flow = INF;
        for (int u = t; u != s; u = parent[u].first) {
            Edge e = g[parent[u].first][parent[u].second];
            flow = min(flow, e.cap - e.flow);
        }

        max_flow += flow;

        for (int u = t; u != s; u = parent[u].first) {
            Edge &e = g[parent[u].first][parent[u].second];
            e.flow += flow;
            g[e.to][e.rev].flow -= flow;
            min_cost += e.cost * flow;
        }
    }

    return { min_cost, max_flow };
}