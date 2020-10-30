// Finds all Biconnected Components in an undirected graph using Tarjan's Algorithm
// An edge which is not in a component (bccs[i].size() > 2) is a bridge, i.e., not part of any cycle.
// Complexity: O(n + m)
struct BCC {
    int n, timer, bccnum = 0;
    stack<pair<int, int>> stck;
    vector<int> in, low, vis, what_block;
    vector<bool> is_articulation;
    vector<vector<int>> block_cut_tree, bccs;

    BCC(int n) : n(n) {
        bccnum = 0;
        timer = 0;
        bccs.resize(n);
        in.resize(n);
        low.resize(n);
        vis.resize(n);
        what_block.resize(n);
        is_articulation.resize(n);
        block_cut_tree.resize(2 * n);
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
                            is_articulation[u] = true;
                            bccs[bccnum].push_back(u);
                        }

                        while (true) {
                            auto edge = stck.top();
                            stck.pop();

                            int a = edge.first, b = edge.second;
                            
                            what_block[a] = bccnum;
                            bccs[bccnum].push_back(a);

                            what_block[b] = bccnum;
                            bccs[bccnum].push_back(b);

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

    void findBCCs() {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                DFS(i);
            }
        }
    }

    // 0 ... bccnum - 1 are blocks.
    // bccnum ... bccnum + number of articulations points are cut points.
    void buildBlockCutTree() {
        int cuts = bccnum;

        for (int v = 0; v < n; v++) {
            if (is_articulation[v]) {
                what_block[v] = cuts++;
            }
        }

        for (int blck = 0; blck < bccnum; blck++) {
            for (auto v : bccs[blck]) {
                if (is_articulation[v]) {
                    block_cut_tree[blck].push_back(what_block[v]);
                    block_cut_tree[what_block[v]].push_back(blck);
                }
            }
        }
    }
};