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
int dist[MAXN], n, m;

void dijkstra_sparse(int s){
    for(int i = 0; i <= n; i++) dist[i] = INF;

    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({ 0, s });

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto e : g[u]){
            for (auto x : g[e.first]) {
                int v = x.first;
                int w = x.second;
                int w_e = e.second;
                if(dist[v] > dist[u] + w + w_e){
                    dist[v] = dist[u] + w + w_e;
                    pq.push({ dist[v], v });
                }
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    dijkstra_sparse(1);

    cout << (dist[n] == INF ? -1:dist[n]) << endl;

    return 0;
}