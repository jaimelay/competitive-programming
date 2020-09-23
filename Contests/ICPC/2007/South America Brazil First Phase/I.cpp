#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 1010;

vector<long long> graph[MAXN], monsters[MAXN];
long long dist[MAXN], room[MAXN], m, n;

// Complexity: O(m * log(n))
void dijkstraSparse(int s){
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[s] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq;
    pq.push({ 0, s });

    while(!pq.empty()){
        long long u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto v : graph[u]) {
            long long w = room[v];

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int g, k;

    while (cin >> m >> n >> g >> k) {
        if (m == 0 && n == 0 && g == 0 && k == 0) {
            break;
        }

        memset(graph, 0, sizeof(graph));
        memset(monsters, 0, sizeof(monsters));
        memset(room, 0, sizeof(room));

        vector<pair<long long, long long>> spells(m);
        for (auto &x : spells) cin >> x.first >> x.second;

        for (int i = 0, a, b; i < g; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 0, monster, life; i < k; i++) {
            cin >> monster >> life;
            monsters[monster].push_back(life);
        }

        vector<long long> dp(1010, INF);
        dp[0] = 0;

        for (int i = 1; i <= 1000; i++) {
            for (int j = 0; j < m; j++) {
                if (i - spells[j].second >= 0) {
                    dp[i] = min(dp[i], dp[i - spells[j].second] + spells[j].first);
                } else {
                    dp[i] = min(dp[i], spells[j].first);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (auto x : monsters[i]) {
                room[i] += dp[x];
            }
        }

        dijkstraSparse(1);

        if (dist[n] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[n] + room[1] << endl;
        }
    }

    return 0;
}