int pai[1000001], n;

void init(){
    for(int i = 1; i <= n; i++)
        pai[i] = i;
}

int find(int v){
    if(pai[v] == v)
        return v;
    return pai[v] = find(pai[v]);
}

bool unions(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return false;
    pai[u] = v;                             // Faz com que o 'v' seja pai de 'u'
}