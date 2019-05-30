
#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int tam = -1;
bool vis[1000];
vector<int> adj[1000];

void DFS(int u){
    vis[u] = true;
    tam++;                  // O que fazer quando entrar no vertice.
    for(auto v : adj[u])
        if(!vis[v]) DFS(v);
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, v, a, x, y;
    scanf("%d", &t);
    while(t--){
        tam = -1;
        memset(vis, false, sizeof(vis));

        scanf("%d", &n);
        scanf("%d %d", &v, &a);

        for(int i = 0; i < a; i++){
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        DFS(n);
        printf("%d\n", tam * 2);
        for(int i = 0; i < a; i++)
            adj[i].clear();
    }
    return 0;
}