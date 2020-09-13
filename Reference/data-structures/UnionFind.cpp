int p[MAXN], sz[MAXN], n;

void preprocess() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 0;
    }
}

int findSet(int v) {
    if (p[v] == v) {
        return v;
    }

    return p[v] = findSet(p[v]);
}

void unionSet(int a, int b){
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