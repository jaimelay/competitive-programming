#include <bits/stdc++.h>

#define MAXN 100010

using namespace std;

vector<int> g[MAXN];
int vis[MAXN], depth[MAXN], parent[MAXN];
map<int, bool> mp;

void find_leaves(int u) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (!vis[v]) {
            if (g[v].size() == 1) mp[v] = 1;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            find_leaves(v);
        }
    }
}

int main(void) {
    int n, k;

    cin >> n >> k;

    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }

    find_leaves(1);
    
    vector<pair<int, int>> leaves;
    for (int i = 2; i <= n; i++) {
        if (mp[i]) {
            leaves.push_back({ depth[i], i });
        }
    }

    sort(leaves.rbegin(), leaves.rend());
    for (int i = 0; i <= n; i++) vis[i] = 0;

    vector<int> val;
    for (int i = 0; i < leaves.size(); i++) {
        int cnt = 0;
        for (int j = leaves[i].second; j != 0; j = parent[j]) {
            if (!vis[j]) {
                cnt++;
                vis[j] = 1;
            }
        }
        val.push_back(cnt);
    }

    sort(val.rbegin(), val.rend());

    int ans = 0;
    for (int i = 0; i < min(k, (int)val.size()); i++) ans += val[i];
    cout << ans << endl;

    return 0;
}