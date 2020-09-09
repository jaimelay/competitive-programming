// Find Strongly Connected Components (SCCs)
// Complexity: O(n + m)

int tin[MAXN], low[MAXN], in_stck[MAXN], timer = 0, sccs_cnt = 0;
stack<int> stck;
vector<int> SCCS[MAXN];

void preprocess() {
    memset(tin, 0, sizeof(tin));
    memset(low, 0, sizeof(low));
    memset(in_stck, 0, sizeof(in_stck));
    memset(SCCS, 0, sizeof(SCCS));
    memset(g, 0, sizeof(g));
    timer = 0;
    sccs_cnt = 0;
    while (!stck.empty()) stck.pop();
}

void tarjan(int u) {
    tin[u] = low[u] = ++timer;
    stck.push(u);
    in_stck[u] = true;

    for (auto v : g[u]) {
        if (tin[v] == 0) {
            tarjan(v);
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