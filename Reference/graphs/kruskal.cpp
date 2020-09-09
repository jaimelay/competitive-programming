// Finding Minimum Spanning Tree
// Complexity: O(m * log(n))

struct Edge {
    int u, v, w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    bool operator < (Edge const& e) {
        return w < e.w;
    }
};

int p[MAXN], sz[MAXN];

int findSet(int v) {
    if (p[v] == v) {
        return v;
    }

    return p[v] = findSet(p[v]);
}

void unionSet(int a, int b) {
    int u = findSet(a);
    int v = findSet(b);

    if (u != v) {
        if (sz[u] < sz[v]) {
            swap(u, v);
        }

        p[v] = u;
        sz[u] += sz[v];
    }
}

vector<Edge> kruskal(vector<Edge> edges) {
    vector<Edge> mst;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 0;
    }

    sort(edges.begin(), edges.end());

    int cost = 0;
    
    for (auto edge : edges) {
        if (findSet(edge.u) != findSet(edge.v)) {
            cost += edge.w;
            mst.push_back(edge);
            unionSet(edge.u, edge.v);
        }
    }

    return mst;
}