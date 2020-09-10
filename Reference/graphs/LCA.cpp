// Complexity: Preprocess: O(n * log(n)); Query LCA: O(log(n));

int LOG_MAX_NODES = 25;
vector<vector<int>> up;
vector<pair<int, long long>> g[MAXN];
vector<int> depth;
vector<long long> dist;

void addEdge(int u, int v, int w = 0) {
    g[u].push_back({ v, w });
    g[v].push_back({ u, w });
}

void DFS(int u, int p) {
    up[u][0] = p;

    for (int l = 1; l <= LOG_MAX_NODES; l++) {
        up[u][l] = up[up[u][l - 1]][l - 1];
    }

    for (auto edge : g[u]) {
        int v = edge.first;
        long long w = edge.second;

        if (v != p) {
            depth[v] = depth[u] + 1;
            dist[v] = dist[u] + w;
            DFS(v, u);
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    for (int i = LOG_MAX_NODES; i >= 0; --i) {
        if (depth[b] - (1 << i) >= depth[a]) {
            b = up[b][i];
        }
    }

    if (a == b) {
        return a;
    }

    for (int i = LOG_MAX_NODES; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

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
    depth.resize(n);
    dist.resize(n);
    LOG_MAX_NODES = (int)ceil(log2(n));
    up.assign(n, vector<int>(LOG_MAX_NODES + 1));

    DFS(root, root);
}