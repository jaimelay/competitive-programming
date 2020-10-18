int sub_tree_size[MAXN], n;
vector<int> centroids;

void DFS(int u, int p) {
    sub_tree_size[u] = 1;
    bool flag = true;

    for (auto v : g[u]) {
        if (v != p) {
            DFS(v, u);
            sub_tree_size[u] += sub_tree_size[v];
            if (sub_tree_size[v] > n / 2) {
                flag = false;
            }
        }
    }

    if ((n - sub_tree_size[u]) > n / 2) {
        flag = false;
    }

    if (flag) {
        centroids.push_back(u);
    }
}

void decomposition() {
    // to implement...
}