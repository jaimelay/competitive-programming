#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

int t, n, m, ans, infec, a, b, cont, g[MAXN][MAXN], vis[MAXN], low[MAXN], filhos[MAXN];

void DFS(int p, int v){
    vis[v] = low[v] = ++cont;
    filhos[v] = 1;
    for(int u = 1; u <= n; u++){
        if(g[v][u]){
            if(!vis[u]){
                DFS(v, u);
                filhos[v] += filhos[u];
                if(low[u] == vis[u] && g[v][u] == 1) ans = max(ans, filhos[u]);
                low[v] = min(low[v], low[u]);
            }else if(u != p){
                low[v] = min(low[v], vis[u]);
            }
        }
    }
}

void init(){
    cont = 0;
    ans = 0;
    memset(g, 0, sizeof(g));
    memset(vis, 0, sizeof(vis));
    memset(low, 0, sizeof(low));
    memset(filhos, 0, sizeof(filhos));
}

int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--){
        init();
        cin >> n >> m >> infec;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            g[a][b]++;
            g[b][a]++;
        }
        DFS(infec, infec);
        cout << ans << endl;
    }
    return 0;
}