#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 1e4 + 10;

vector<pair<int, int>> g[MAXN];
int ans[MAXN], E[MAXN], W[MAXN][MAXN], degree[MAXN], n, cap;

int DFS(int u, int p) {
    for (auto edge : g[u]) {
        int v = edge.first; 
        int w = edge.second;

        if (v != p) {
            if (degree[v] == 1) {
                ans[u] += (2 * (((E[v] + cap - 1) / cap) * w));
            } else {
                ans[u] += DFS(v, u);
            }
            E[u] += E[v];
        }
    }

    return ans[u] + 2 * (((E[u] + cap - 1) / cap) * W[u][p]);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> cap;

    for (int i = 1; i <= n; i++) {
        cin >> E[i];
    }

    for (int i = 0, u, v, w; i < n - 1; i++) {
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
        W[u][v] = w;
        W[v][u] = w;
        degree[u]++;
        degree[v]++;
    }

    DFS(1, 0);

    cout << ans[1] << "\n";

    return 0;
}