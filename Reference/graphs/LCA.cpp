// Complexity: Preprocess: O(n * log(n)); Query LCA: O(log(n));

int LOG_MAX_NODES = 25;
vector<vector<int>> up;
vector<pair<int, int>> g[MAXN];
vector<int> depth;
vector<int> dist;
vector<vector<int>> mx_edge_weight;

void addEdge(int u, int v, int w = 0) {
    g[u].push_back({ v, w });
    g[v].push_back({ u, w });
}

void DFS(int u, int p, int w = 0) {
    up[u][0] = p;
    // mx_edge_weight[u][0] = w;

    for (int l = 1; l <= LOG_MAX_NODES; l++) {
        up[u][l] = up[up[u][l - 1]][l - 1];
        // mx_edge_weight[u][l] = max(mx_edge_weight[up[u][l - 1]][l - 1], mx_edge_weight[u][l - 1]);
    }

    for (auto &edge : g[u]) {
        int v = edge.first;
        long long w = edge.second;

        if (v != p) {
            depth[v] = depth[u] + 1;
            // dist[v] = dist[u] + w;
            DFS(v, u, w);
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    int mx_edge = 0;

    for (int i = LOG_MAX_NODES; i >= 0; --i) {
        if (depth[b] - (1 << i) >= depth[a]) {
            // mx_edge = max(mx_edge, mx_edge_weight[b][i]);
            b = up[b][i];
        }
    }

    if (a == b) {
        return a;
    }

    for (int i = LOG_MAX_NODES; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            // mx_edge = max({ mx_edge, mx_edge_weight[a][i], mx_edge_weight[b][i] });
            a = up[a][i];
            b = up[b][i];
        }
    }

    // mx_edge = max({ mx_edge, mx_edge_weight[a][0], mx_edge_weight[b][0] });
    return up[a][0];
}

int liftingUp(int a, int x) {
    for (int i = LOG_MAX_NODES; i >= 0; i--) {
        if (x - (1 << i) >= 0) {
            a = up[a][i];
            x -= (1 << i);
        }
    }

    return a;
}

void preprocess(int root, int n) {
    LOG_MAX_NODES = (int)ceil(log2(n));
    depth.resize(n);
    up.assign(n, vector<int>(LOG_MAX_NODES + 1));
    // mx_edge_weight.assign(n, vector<int>(LOG_MAX_NODES + 1));
    // dist.resize(n);

    DFS(root, root);
}