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
pair<int, int> parent[MAXN];
int n, m;

void add_edge(int from, int to, long long cap, long long cost) {
    g[from].push_back(Edge(to, 0, cap, cost, g[to].size()));
    g[to].push_back(Edge(from, 0, 0, -cost, g[from].size() - 1));
}

void MCMFBellmanFord(int s) {
    fill(phi, phi + MAXN, INF);
    phi[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (Edge e : g[u]) {
                if (!e.cap) {
                    continue;
                }

                int v = e.to;
                long long w = e.cost;
                phi[v] = min(phi[v], phi[u] + w);
            }
        }
    }
}

// Complexity: O(m * log(n))
bool MCMFDjikstraSparse(int s, int t) {
    for (int i = 0; i < MAXN; i++) {
        dist[i] = INF;
        parent[i] = { -1, -1 };
    }

    dist[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0, s });

    bool flag = false;
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (u == t) flag = true;

        if (d != dist[u]) continue;

        for (int i = 0; i < int(g[u].size()); i++) {
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
		if (phi[i] < INF && dist[i] < INF) {
			phi[i] += dist[i];
        }
    }

    return flag;
}

// Complexity: O(n^2 + m)
bool MCMFDjikstraDense(int s, int t) {
    for (int i = 0; i < MAXN; i++) {
        dist[i] = INF;
        parent[i] = { -1, -1 };
    }

    vector<bool> vis(n, false);

    dist[s] = 0;
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
        for (int j = 0; j < int(g[u].size()); j++) {
            Edge e = g[u][j];
            int v = e.to;

            if (e.cap - e.flow <= 0) {
                continue;
            }

            long long w = e.cost + phi[u] - phi[v];

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = { u, j };
            }
        }
    }

	for (int i = 0; i < MAXN; i++) {
		if (phi[i] < INF && dist[i] < INF) {
			phi[i] += dist[i];
        }
    }

    return parent[t].first >= 0;
}

pair<long long, long long> MCMF(int s, int t, int k = INF) {
    long long min_cost = 0, max_flow = 0, total_cost = 0;

    MCMFBellmanFord(s);

    while (MCMFDjikstraSparse(s, t)) {
        long long flow = INF;

        for (int u = t; u != s; u = parent[u].first) {
            Edge e = g[parent[u].first][parent[u].second];
            flow = min(flow, e.cap - e.flow);
        }

        for (int u = t; u != s; u = parent[u].first) {
            Edge &e = g[parent[u].first][parent[u].second];
            e.flow += flow;
            g[e.to][e.rev].flow -= flow;
            min_cost += e.cost * flow;
            total_cost += e.cost;
        }

        max_flow += flow;
    }

    return { min_cost, max_flow };
}