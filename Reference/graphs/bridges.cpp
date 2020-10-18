// Description: Returns in undirected graph all bridges.
// Complexity: O(n + m)
struct Bridges {
    vector<int> tin, low;
    int timer;
    map<pair<int, int>, bool> bridges;

    Bridges(int n) {
        tin.resize(n);
        low.resize(n);
        timer = 0;
    }

    void DFS(int u, int p = -1) {
        tin[u] = low[u] = ++timer;

        for (auto v : g[u]) {
            if (v == p) {
                continue;
            }

            if (tin[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                DFS(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > tin[u]) {
                    bridges[{ u, v }] = true;
                }
            }
        }
    }
};