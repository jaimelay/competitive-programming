// Heavy Light Decomposition
// Complexity:
// build: O(n)
// queryPath, updatePath: O(log^2(n))
// querySubtree, updateSubtree, LCA: O(log(n))
struct HLD {
    vector<int> parent, sz, heavy, head, pos, weight, chains;
    int curr_pos, neutral;
    bool WEIGHTS_IN_EDGE;
    SegmentTreeLazy *segtree; // Import SegmentTreeLazy algorithm and change to class and put all in public.

    HLD(int n, bool in_edge = false) {
        parent.resize(n);
        sz.resize(n);
        heavy.resize(n);
        head.resize(n);
        pos.resize(n);
        weight.resize(n);
        chains.resize(n);

        WEIGHTS_IN_EDGE = in_edge;
        curr_pos = -1;
        neutral = 0;
        DFS(0);
        buildHLD(0);
        segtree = new SegmentTreeLazy(curr_pos, chains);
    }

    void DFS(int u, int p = -1) {
        sz[u] = 1;
        for (auto &edge : g[u]) {
            int v = edge.first, w = edge.second;
            if (v != p) {
                if (WEIGHTS_IN_EDGE) {
                    weight[v] = w;
                }

                DFS(v, u);
                sz[u] += sz[v];

                if (sz[v] > sz[g[u][0].first] or g[u][0].first == p) {
                    swap(edge, g[u][0]);
                }
            }
        }
    }

    void buildHLD(int u, int p = -1) {
        parent[u] = p;
        pos[u] = ++curr_pos;
        chains[pos[u]] = weight[u];

        for (auto &edge : g[u]) {
            int v = edge.first;
            if (v != p) {
                heavy[v] = (edge == g[u].front() ? heavy[u] : v);
                buildHLD(v, u);
            }
        }
    }

    int queryPath(int a, int b) {
        if (WEIGHTS_IN_EDGE and a == b) return neutral;
        if (pos[a] < pos[b]) swap(a, b);
        if (heavy[a] == heavy[b]) return segtree->query(pos[b] + WEIGHTS_IN_EDGE, pos[a]);
        return max(segtree->query(pos[heavy[a]], pos[a]), queryPath(parent[heavy[a]], b));
    }

    void updatePath(int a, int b, int x) {
        if (WEIGHTS_IN_EDGE and a == b) return;
        if (pos[a] < pos[b]) swap(a, b);
        if (heavy[a] == heavy[b]) return segtree->update(pos[b] + WEIGHTS_IN_EDGE, pos[a], x);
        segtree->update(pos[heavy[a]], pos[a], x);
        updatePath(parent[heavy[a]], b, x);
    }

    int querySubtree(int a) {
        if (WEIGHTS_IN_EDGE and sz[a] == 1) return neutral;
        return segtree->query(pos[a] + WEIGHTS_IN_EDGE, pos[a] + sz[a] - 1);
    }

    void updateSubtree(int a, int x) {
        if (WEIGHTS_IN_EDGE and sz[a] == 1) return;
        segtree->update(pos[a] + WEIGHTS_IN_EDGE, pos[a] + sz[a] - 1, x);
    }

    int LCA(int a, int b) {
        if (pos[a] < pos[b]) swap(a, b);
        return heavy[a] == heavy[b] ? b : LCA(parent[heavy[a]], b);
    }
};