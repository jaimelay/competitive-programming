vector<int> g[n];
int vis[n];

int tam = 0;

void DFS(int v){
    vis[v] = 1;
    for(auto u : g[v])
        if(!vis[v]) DFS(u);
}

// Cobertura Minima
// 0 = Nao visitado, 1 = Visitado, 2 = Vertice da cobertura
void DFS(int v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(vis[u] == 0){
            DFS(u);
            if(vis[u] == 1) vis[v] = 2;
        }
    }
}

// O vertice u esta conectado com dest?
bool isConnect(int u, int dest){
    vis[u] = true;
    if(u == dest) return true;
    for(auto v : adj[u])
        if(connect(v, dest)) return true;
    return false;
}


