#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 550;

int n, m;
int dist[MAXN];
vector<int> parent[MAXN];
int g[MAXN][MAXN];

void dijkstraDense(int s) {
    for(int i = 0; i <= n; i++) {
        dist[i] = INF;
    }

    memset(parent, 0, sizeof(parent));
    vector<bool> vis(n, false);

    dist[s] = 0;
    parent[s] = { -1 };

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) {
            break;
        }

        vis[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (g[u][v] == 0) {
                continue;
            }

            int w = g[u][v];

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v].clear();
                parent[v].push_back(u);
            } else if (dist[u] + w == dist[v]) {
                parent[v].push_back(u);
            }
        } 
    }
}

vector<int> path;
vector<vector<int>> paths;

void DFS(int u) {
    if (u == -1) {
        paths.push_back(path);
        return;
    }

    for (auto v : parent[u]) {
        path.push_back(u);
        DFS(v);
        path.pop_back();
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m) {
        if (n == 0 || m == 0) {
            break;
        }

        memset(g, 0, sizeof(g));

        int s, d;
        cin >> s >> d;
        
        for (int i = 0, u, v, w; i < m; i++) {
            cin >> u >> v >> w;
            g[u][v] = w;
        }

        dijkstraDense(s);

        path.clear();
        paths.clear();
        DFS(d);

        for (auto p : paths) {
            reverse(p.begin(), p.end());

            for (int i = 0; i < int(p.size()) - 1; i++) {
                g[p[i]][p[i + 1]] = 0;
            }
        }

        dijkstraDense(s);

        cout << (dist[d] == INF ? -1:dist[d]) << endl;
    }

    return 0;
}