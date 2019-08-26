int vis[MAXN], low[MAXN], ap[MAXN], cont;

void articulation_point(int p, int v){
    vis[v] = low[v] = ++cont;
    for(auto u : g[v]){
        if(!vis[u]){
            articulation_point(v, u);
            if(low[u] >= vis[v]) ap[v]++;
            low[v] = min(low[v], low[u]);
        }else if(u != p){
            low[v] = min(low[v], vis[u]);
        }
    }
}

vector<int> isArticulationPoint(){
    vector<int> points;
    for(int i = 1; i <= n; i++){
        if(!vis[i]) articulation_point(i, i);
    }

    for(int i = 1; i <= n; i++){
        if(i == 1 && ap[1] > 1) points.push_back(1);
        else if(i != 1 && ap[i] > 0) points.push_back(i);
    }

    return points;
}

void init(){
    cont = 0;
    memset(vis, 0, sizeof(vis));
    memset(low, 0, sizeof(low));
    memset(ap, 0, sizeof(ap));
    memset(g, 0, sizeof(g));
}