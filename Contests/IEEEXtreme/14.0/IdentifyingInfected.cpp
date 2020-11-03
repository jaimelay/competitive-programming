#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 100010;

vector<int> g[MAXN];

// Finds all Biconnected Components in an undirected graph using Tarjan's Algorithm
// An edge which is not in a component (bccs[i].size() > 2) is a bridge, i.e., not part of any cycle.
// Complexity: O(n + m)
struct BCC {
    int n, timer, bccnum = 0;
    stack<pair<int, int>> stck;
    vector<int> in, low, vis, what_block, roots;
    vector<bool> is_articulation;
    vector<vector<int>> block_cut_tree;
    vector<set<int>> bccs;

    int LOG_MAX_NODES = 25;
    vector<vector<int>> up;
    vector<int> depth, qntd_art;

    BCC(int n) : n(n) {
        bccnum = 0;
        timer = 0;
        bccs.resize(n);
        in.resize(n);
        low.resize(n);
        vis.resize(n);
        what_block.resize(n, -1);
        is_articulation.resize(n);
        block_cut_tree.resize(2 * n);
        while (!stck.empty()) stck.pop();

        LOG_MAX_NODES = (int)ceil(log2(2 * n));
        depth.resize(2 * n);
        qntd_art.resize(2 * n);
        up.assign(2 * n, vector<int>(LOG_MAX_NODES + 1));
    }

    void DFS(int u, int p = -1) {
        vis[u] = true;
        low[u] = in[u] = timer++;
        int children = 0;

        for (int v : g[u]) {
            if (v != p) {
                if (!vis[v]) {
                    stck.emplace( v, u );
                    DFS(v, u);
                    low[u] = min(low[u], low[v]);

                    if (low[v] >= in[u]) {
                        if (p != -1) {
                            is_articulation[u] = true;
                        }

                        while (true) {
                            auto edge = stck.top();
                            stck.pop();

                            int a = edge.first, b = edge.second;
                            
                            what_block[a] = bccnum;
                            what_block[b] = bccnum;
                            bccs[bccnum].insert(a);
                            bccs[bccnum].insert(b);

                            if (a == v && b == u) {
                                break;
                            }
                        }

                        bccnum++;
                    }

                    children++;
                } else if (in[v] < in[u]) {
                    low[u] = min(low[u], in[v]);
                    stck.emplace(v, u);
                }
            }
        }

        if (p == -1 && children > 1) {
            is_articulation[u] = true;
        }
    }

    void findBCCs() {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                roots.push_back(bccnum);
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

    // Complexity: Preprocess: O(n * log(n)); Query LCA: O(log(n));
    void DFSLCA(int u, int p, int cut_points = 0) {
        up[u][0] = p;
        qntd_art[u] = cut_points;

        for (int l = 1; l <= LOG_MAX_NODES; l++) {
            up[u][l] = up[up[u][l - 1]][l - 1];
        }

        for (auto v : block_cut_tree[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                DFSLCA(v, u, cut_points + (v >= bccnum));
            }
        }
    }

    int LCA(int a, int b) {
        if (depth[a] > depth[b]) {
            swap(a, b);
        }

        for (int i = LOG_MAX_NODES; i >= 0; --i) {
            if (depth[b] - (1 << i) >= depth[a]) {
                b = up[b][i];
            }
        }

        if (a == b) {
            return a;
        }

        for (int i = LOG_MAX_NODES; i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
    
        return up[a][0];
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    BCC biconnected_components(n);
    biconnected_components.findBCCs();
    biconnected_components.buildBlockCutTree();

    for (auto x : biconnected_components.roots) {
        biconnected_components.DFSLCA(x, x);
    }

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int blockA = biconnected_components.what_block[a];
        int blockB = biconnected_components.what_block[b];

        int num_of_bccs = biconnected_components.bccnum;

        int qntd_art_a = biconnected_components.qntd_art[blockA];
        int qntd_art_b = biconnected_components.qntd_art[blockB];

        if (blockA == -1 || blockB == -1) {
            cout << 2 << endl;
        } else if (blockA == blockB) {
            cout << 2 << endl;
        } else {
            int lc = biconnected_components.LCA(blockA, blockB);
            int qntd_art_lca = biconnected_components.qntd_art[lc];
            int ans = qntd_art_a + qntd_art_b - 2 * qntd_art_lca + 2 + (lc >= num_of_bccs);

            if (blockA >= num_of_bccs) {
                ans--;
            }

            if (blockB >= num_of_bccs) {
                ans--;
            }

            cout << ans << endl;
        }
    }

    return 0;
}