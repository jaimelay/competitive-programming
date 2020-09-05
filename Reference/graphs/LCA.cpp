// Complexity: Preprocess: O(n * log(n)); Query LCA: O(log(n));

int LOG_MAX_NODES = 25;
vector<vector<int>> up;
vector<int> G[MAXN], depth;

void DFS(int v, int p) {
    up[v][0] = p;

    for (int u : G[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            DFS(u, v);
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
    depth.resize(n + 10);
    LOG_MAX_NODES = (int)ceil(log2(n + 1));
    up.assign(n + 10, vector<int>(LOG_MAX_NODES));
    DFS(root, root);
    for (int l = 1; l <= LOG_MAX_NODES; l++) {
        for (int u = 1; u <= n; u++) {
            up[u][l] = up[up[u][l - 1]][l - 1];
        }
    }
}