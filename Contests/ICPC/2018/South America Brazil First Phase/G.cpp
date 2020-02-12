#include <bits/stdc++.h>

using namespace std;

#define MAXN 20100
#define INF 2000000000

struct Edge {
    int to;
    int flow;
    int cap;
    int rev;
    int time;
};

vector<Edge> g[MAXN];
int dist[MAXN], ptr[MAXN], ans[MAXN], src, sink, n;
int p1, r1, c;
map<pair<int, int>, int> mp;
vector<int> p, r;

void add_edge(int from, int to, int cap, int time = -1) {
    Edge a = { to, 0, cap, (int)g[to].size(), time };
    Edge b = { from, 0, 0, (int)g[from].size(), time };
    g[from].push_back(a);
    g[to].push_back(b);
}

bool dinic_bfs() {
    fill(dist, dist + MAXN, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (Edge e : g[u]) {
            int v = e.to;
            if (dist[v] < 0 && e.flow < e.cap) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[sink] >= 0;
}

int dinic_dfs(int u, int flow) {
    if (u == sink) return flow;

    for (int &i = ptr[u]; i < g[u].size(); i++) {
        Edge &e = g[u][i];
        if (e.cap > e.flow) {
            int v = e.to;
            if (dist[v] == dist[u] + 1) {
                int tmp_flow = dinic_dfs(v, min(flow, e.cap - e.flow));
                if (tmp_flow > 0) {
                    e.flow += tmp_flow;
                    g[v][e.rev].flow -= tmp_flow;
                    return tmp_flow;
                }
            }
        }
    }

    return 0;
}

int dinic(int s, int t) {
    src = s;
    sink = t;
    int max_flow = 0;

    while (dinic_bfs()) {
        fill(ptr, ptr + MAXN, 0);                                           
        while (int flow = dinic_dfs(src, INF)) max_flow += flow;
    }

    return max_flow;
}

void createGraph(int time) {
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= r1; i++) {
        add_edge(0, i, r[i - 1]);
    }
    for (int i = r1 + 1, j = 0; i <= r1 + p1; i++, j++) {
        add_edge(i, r1 + p1 + 1, p[j]);
    }
    for (auto x : mp) {
        if (x.second <= time)
            add_edge(x.first.second, r1 + x.first.first, r[x.first.second - 1], x.second);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> p1 >> r1 >> c;
    n = p1 + r1 + 1;
    int total_posto = 0;
    for (int i = 0, x; i < p1; i++) {
        cin >> x;
        p.push_back(x);
        total_posto += x;
    }
    for (int i = 0, x; i < r1; i++) {
        cin >> x;
        r.push_back(x);
    }
    for (int i = 1; i <= r1; i++) {
        add_edge(0, i, r[i - 1]);
    }

    for (int i = r1 + 1, j = 0; i <= r1 + p1; i++, j++) {
        add_edge(i, r1 + p1 + 1, p[j]);
    }

    int max_time = -1;
    for (int i = 0, a, b, w; i < c; i++) {
        cin >> a >> b >> w;
        add_edge(b, r1 + a, r[b - 1], w);
        mp[{ a, b }] = w;
        max_time = max(max_time, w);
    }

    int max_flow = dinic(0, n);
    if (max_flow != total_posto) {
        cout << -1 << endl;
    } else {
        int l = 0, r = max_time;
        while (l <= r) {
            int mid = (l + r) / 2;
            createGraph(mid);
            if (dinic(0, n) == total_posto) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << r + 1 << endl;
    }

    return 0;
}