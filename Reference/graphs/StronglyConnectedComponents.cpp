// Finds all Strongly Connected Components in a directed graph using Tarjan's Algorithm.
// Complexity: O(n + m)
struct SCC {
    vector<int> tin, low, in_stck;
    int timer = 0, sccs_cnt = 0, n;
    stack<int> stck;
    vector<vector<int>> SCCS;

    SCC(int n) : n(n) {
        SCCS.resize(n);
        tin.resize(n);
        low.resize(n);
        in_stck.resize(n);
        timer = 0;
        sccs_cnt = 0;
        while (!stck.empty()) stck.pop();
    }

    void DFS(int u) {
        tin[u] = low[u] = ++timer;
        stck.push(u);
        in_stck[u] = true;

        for (auto v : g[u]) {
            if (tin[v] == 0) {
                DFS(v);
                low[u] = min(low[u], low[v]);
            } else if (in_stck[v]) {
                low[u] = min(low[u], tin[v]);
            }
        }

        if (tin[u] == low[u]) {
            while (!stck.empty()) {
                int x = stck.top();
                stck.pop();

                in_stck[x] = false;
                SCCS[sccs_cnt].push_back(x);

                if (x == u) {
                    break;
                }
            }
            sccs_cnt++;
        }
    }
};