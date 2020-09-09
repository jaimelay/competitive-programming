int p[MAXN], sz[MAXN], n;

void preprocess() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int findSet(int v) {
    if (p[v] == v) {
        return v;
    }

    return p[v] = findSet(p[v]);
}

void unionSet(int a, int b){
    int u = findSet(u);
    int v = findSet(v);

    if (u != v) {
        if(sz[u] < sz[v]) {
            swap(u, v);
        }

        p[v] = u;
        sz[u] += sz[v];
    }
}