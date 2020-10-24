// Finds all Biconnected Components in an undirected graph using Tarjan's Algorithm
// An edge which is not in a component && (bccs[i].size() > 2) is a bridge, i.e., not part of any cycle.
// Complexity: O(n + m)
struct BCC {
    int n, timer, bccnum = 0;
    vector<set<int>> bccs;
    vector<vector<int>> block_cut;
    vector<int> in, low, vis;
    stack<pair<int, int>> stck;
    vector<int> articulations;

    BCC(int n) : n(n) {
        bccnum = 0;
        timer = 0;
        bccs.resize(n);
        in.resize(n);
        low.resize(n);
        vis.resize(n);
        block_cut.resize(n);
        articulations.clear();
        while (!stck.empty()) stck.pop();
    }

    void DFS(int u, int p = -1) {
        vis[u] = true;
        low[u] = in[u] = timer++;

        for (int v : g[u]) {
            if (v != p) {
                if (!vis[v]) {
                    stck.emplace( v, u );
                    DFS(v, u);
                    low[u] = min(low[u], low[v]);

                    if (low[v] >= in[u]) {
                        if (in[u] > 1 || in[v] > 2) {
                            articulations.push_back(u);
                        }

                        while (true) {
                            auto edge = stck.top();
                            stck.pop();

                            int a = edge.first, b = edge.second;
                            
                            bccs[bccnum].insert(a);
                            bccs[bccnum].insert(b);

                            if (a == v && b == u) {
                                break;
                            }
                        }

                        bccnum++;
                    }
                } else if (in[v] < in[u]) {
                    low[u] = min(low[u], in[v]);
                    stck.emplace(v, u);
                }
            }
        }
    }

    void buildBlockCutTree() {
        int nodes = bccnum;

        for (auto art : articulations) {
            for (int i = 0; i < bccnum; i++) {
                if (binary_search(bccs[i].begin(), bccs[i].end(), art)) {
                    block_cut[nodes].push_back(i);
                    block_cut[i].push_back(nodes);
                }
            }
            nodes++;
        }
    }

    void findBCCs() {
        for (int i = 1 ; i <= n; ++i ) {
            if (!vis[i]) {
                DFS(i);
            }
        }
    }
};