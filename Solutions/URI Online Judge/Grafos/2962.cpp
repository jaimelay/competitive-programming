#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 1e3 + 10;

int m, n, k, vis[MAXN];
vector<int> g[MAXN];

struct Sensor {
    int x, y, s;

    Sensor(int _x, int _y, int _s) { 
        this->x = _x;
        this->y = _y;
        this->s = _s;
    }

    bool isConnected(Sensor b) {
        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y)) <= s + b.s;
    }
};

void DFS(int u) {
    vis[u] = 1;
    
    for (auto v : g[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k;

    vector<Sensor> v;
    for (int i = 0, x, y, s; i < k; i++) {
        cin >> x >> y >> s;
        v.push_back(Sensor(x, y, s));
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (v[i].isConnected(v[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }

        if (v[i].x - v[i].s <= 0 || v[i].y + v[i].s >= n) {
            g[k].push_back(i);
            g[i].push_back(k);
        }
        
        if (v[i].x + v[i].s >= m || v[i].y - v[i].s <= 0) {
            g[k + 1].push_back(i);
            g[i].push_back(k + 1);
        }
    }

    DFS(k);

    cout << (vis[k + 1] ? "N":"S") << endl;

    return 0;
}