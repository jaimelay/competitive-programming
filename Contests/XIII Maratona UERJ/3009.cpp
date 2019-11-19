#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

vector<int> g[MAXN];
int q, n, m;
bool vis[MAXN], vis2[MAXN];
vector<int> ot;

void ordenacaoTopologica(int v){
    vis[v] = 1;
    for(auto u : g[v])
        if(!vis[u]) ordenacaoTopologica(u);
    ot.push_back(v);
}

int solve(int v){
    vis2[v] = 1;
    for(auto u : g[v])
        if(!vis2[u]) solve(u);
}

void init(){
    memset(g, 0, sizeof(g));
    memset(vis, 0, sizeof(vis));
    memset(vis2, 0, sizeof(vis2));
    ot.clear();
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> q;
    while(q--){
        init();

        cin >> n >> m;
        for(int i = 0, u, v; i < m; i++){
            cin >> u >> v;
            g[u].push_back(v);
        }

        for(int i = 1; i <= n; i++)
            if(!vis[i]) ordenacaoTopologica(i);

        solve(ot[ot.size() - 1]);

        bool flag = true;
        for(int i = 1; i <= n; i++)
            if(!vis2[i]){
                flag = false;
                break;
            } 
        
        cout << (flag ? "S":"N") << endl;
    }

    return 0;
}