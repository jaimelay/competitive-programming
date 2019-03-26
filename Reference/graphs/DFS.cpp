// Busca por profundidade - Depth First Search

vector<int> adj[n];
int vis[n];

int tam = 0;

void DFS(int u){
    vis[u] = true;
    tam++;                  // O que fazer quando entrar no vertice.
    for(auto v : adj[u])
        if(!vis[u]) DFS(v);
}

// O vertice u esta conectado com dest?
bool isConnect(int u, int dest){
    vis[u] = true;
    if(u == dest) return true;
    for(auto v : adj[u])
        if(connect(v, dest)) return true;
    return false;
}
