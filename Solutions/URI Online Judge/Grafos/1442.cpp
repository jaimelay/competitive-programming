#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 10e3 + 10;

int n, m;
bool flag;
int sccs_nodes[MAXN];

struct Graph {
    vector<int> adj[MAXN];
    int tin[MAXN], low[MAXN], in_stck[MAXN], vis[MAXN];
    int n, m, timer = 0, sccs_cnt = 0;
    stack<int> stck;

    Graph(int _n, int _m) {
        this->n = _n;
        this->m = _m;
    }

    void tarjan(int u) {
        tin[u] = low[u] = ++timer;
        stck.push(u);
        in_stck[u] = true;

        for (auto v : adj[u]) {
            if (tin[v] == 0) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (in_stck[v]) {
                low[u] = min(low[u], tin[v]);
            }
        }

        if (tin[u] == low[u]) {
            sccs_cnt++;

            while (!stck.empty()) {
                int x = stck.top();
                stck.pop();

                in_stck[x] = false;
                sccs_nodes[x] = sccs_cnt;

                if (x == u) {
                    break;
                }
            }
        }
    }

    void findBridges(int u, int p = -1) {
        tin[u] = low[u] = ++timer;

        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }

            if (tin[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                findBridges(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    if (sccs_nodes[v] != sccs_nodes[u]) {
                        flag = false;
                        break;
                    }
                }
            }
        }
    }

    void DFS(int u) {
        vis[u] = 1;

        for (auto v : adj[u]) {
            if (!vis[v]) {
                DFS(v);
            }
        }
    }

    int getSCCS() {
        memset(tin, 0, sizeof(tin));
        memset(low, 0, sizeof(low));
        memset(in_stck, 0, sizeof(in_stck));
        timer = 0;
        sccs_cnt = 0;
        while (!stck.empty()) stck.pop();

        for (int i = 1; i <= n; i++) {
            if (!tin[i]) {
                tarjan(i);
            }
        }

        return sccs_cnt;
    }

    bool isConnected() {
        memset(vis, 0, sizeof(vis));

        DFS(1);

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                return false;
            }
        }

        return true;
    }

    void getBridges() {
        memset(low, 0, sizeof(low));
        memset(tin, 0, sizeof(tin));
        timer = 0;

        for (int i = 1; i <= n; i++) {
            if (!tin[i]) {
                findBridges(i);
            }
        }
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m) {
        memset(sccs_nodes, 0, sizeof(sccs_nodes));
        
        Graph directed(n, m), undirected(n, m);

        for (int i = 0, u, v, dir; i < m; i++) {
            cin >> u >> v >> dir;
            
            if (i == 0) {
                continue;
            }

            if (dir == 1) {
                directed.adj[u].push_back(v);
            } else {
                directed.adj[u].push_back(v);
                directed.adj[v].push_back(u);
            }

            undirected.adj[u].push_back(v);
            undirected.adj[v].push_back(u);
        }

        int sccs_cnt = directed.getSCCS();

        if (sccs_cnt == 1) {
            cout << "-" << endl;
            continue;
        }

        if (undirected.isConnected() == false) {
            cout << "*" << endl;
            continue;
        }

        flag = true;

        undirected.getBridges();

        if (flag) {
            cout << "1" << endl;
        } else {
            cout << "2" << endl;
        }

    }

    return 0;
}