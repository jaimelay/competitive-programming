// Complexity: O(n + m)

int tin[MAXN], low[MAXN], timer = 0;
vector<pair<int, int>> bridges;

void findBridges(int u, int p = -1) {
    tin[u] = low[u] = ++timer;

    for (auto v : g[u]) {
        if (v == p) {
            continue;
        }

        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            findBridges(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                if (bridges[{ v, u }] != 0) {
                    bridges[{ u, v }]++;
                } else if (bridges[{ u, v }] != 0) {
                    bridges[{ v, u }]++;
                } else {
                    bridges[{ u, v }]++;
                }
            }
        }
    }
}