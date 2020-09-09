#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 5e4 + 10;

struct Edge {
    int u, v, w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    bool operator < (Edge const& e) {
        return w < e.w;
    }
};

int n, m, s;
int p[MAXN], ans[MAXN];
vector<int> sz[MAXN];
pair<int, int> q[MAXN];
vector<Edge> g;

int findSet(int v) {
    if (p[v] == v) {
        return v;
    }

    return p[v] = findSet(p[v]);
}

void unionSet(int u, int v, int w) {
    u = findSet(u);
    v = findSet(v);

    if (u != v) {
        if (sz[u].size() < sz[v].size()) {
            swap(u, v);
        }

        p[v] = u;

        for (auto x : sz[v]) {
            if (ans[x] == -1) {
                if (findSet(q[x].first) == findSet(q[x].second)) {
                    ans[x] = w;
                }
            }

            sz[u].push_back(x);
        }

        sz[v].clear();
    }

}

void kruskal(vector<Edge> edges) {
    vector<Edge> mst;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    sort(edges.rbegin(), edges.rend());

    int cost = 0;
    
    for (auto edge : edges) {
        if (findSet(edge.u) != findSet(edge.v)) {
            cost += edge.w;
            mst.push_back(edge);
            unionSet(edge.u, edge.v, edge.w);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m >> s) {
        g.clear();
        memset(q, 0, sizeof(q));
        memset(ans, -1, sizeof(ans));
        for (int i = 1; i <= n; i++) {
            sz[i].clear();
        }

        for (int i = 0, u, v, w; i < m; i++) {
            cin >> u >> v >> w;
            g.push_back(Edge(u, v, w));
        }

        for (int i = 0, a, b; i < s; i++) {
            cin >> a >> b;
            q[i] = { a, b };
            sz[a].push_back(i);
            sz[b].push_back(i);
        }

        kruskal(g);

        for (int i = 0; i < s; i++) {
            cout << ans[i] << endl;
        }
    }

    return 0;
}