#include <bits/stdc++.h>

#define MAXN 1010
#define NINF -9999

using namespace std;

int vis[MAXN], dist[MAXN], maior, start_point, end_point, p, q, n;
vector<int> g[MAXN];
stack<int> topoSort;

void topological_sort(int v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(!vis[u]) topological_sort(u);
    }
    topoSort.push(v);
}

void longest_path(int src){
    dist[src] = 0;
    maior = 0;
    while(!topoSort.empty()){
        int v = topoSort.top();
        topoSort.pop();
        if(dist[v] != NINF){
            for(auto u : g[v]){
                dist[u] = max(dist[u], dist[v] + 1);
            }
        }
        maior = max(maior, dist[v]);
    }
    for(int i = 1; i <= n; i++){
        if(maior == dist[i]){
            end_point = i;
            break;
        }
    }
}

void init(){
    memset(g, 0, sizeof(g));
    memset(dist, NINF, sizeof(dist));
    memset(vis, 0, sizeof(vis));
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cas = 0;
    while(cin >> n, n){
        init();

        cin >> start_point;

        while(cin >> p >> q, p, q){
            g[p].push_back(q);
        }

        for(int i = 1; i <= n; i++){
            if(!vis[i]) topological_sort(i);
        }

        longest_path(start_point);

        cout << "Case " << ++cas << ": The longest path from " << start_point << " has length " << maior << ", finishing at " << end_point << "." << endl << endl;
    }
    return 0;
}