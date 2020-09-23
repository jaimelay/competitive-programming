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

vector<int> g[MAXN];
int tin[MAXN], low[MAXN], timer = 0, cnt = 0;

void findBridges(int u, int p = -1) {
    tin[u] = low[u] = ++timer;

    for (auto v : g[u]) {
        if (v == p) {
            continue;
        }

        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            findBridges(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                cnt++;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        if (n == 0 || m == 0) {
            break;
        }

        memset(g, 0, sizeof(g));
        memset(tin, 0, sizeof(tin));
        memset(low, 0, sizeof(low));
        timer = 0;

        for (int i = 0, a, b; i < m; i++) {
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        bool ans = false;
        cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (!tin[i]) {
                findBridges(i);
                if (cnt > 0) {
                    ans = true;
                    break;
                }
            }
        }

        cout << (ans ? "N":"S") << endl;
    }
    cout << endl;

    return 0;
}