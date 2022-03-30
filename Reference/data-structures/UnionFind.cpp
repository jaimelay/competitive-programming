struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return (parent[u] == u ? u : parent[u] = find(parent[u]));
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);

        if (u != v) {
            if (sz[u] < sz[v]) {
                swap(u, v);
            }

            parent[v] = u;
            sz[u] += sz[v];
        }
    }

    bool insideSameSet(int u, int v) {
        return find(u) == find(v);
    }

    int getSize(int u) {
        return sz[find(u)];
    }
};