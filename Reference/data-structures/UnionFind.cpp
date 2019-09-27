int pai[MAXN], qntd[MAXN], n;

void init(){
    for(int i = 1; i <= n; i++) pai[i] = i;
}

int find(int v){
    if(pai[v] == v)
        return v;
    return pai[v] = find(pai[v]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(qntd[u] < qntd[v]) swap(u, v);
    pai[u] = v;
    qntd[v] += qntd[u];
}