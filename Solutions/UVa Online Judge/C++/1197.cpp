#include <bits/stdc++.h>

#define MAXN 30010

using namespace std;

int vis[MAXN], n, m, a, ans;
vector<int> g[MAXN];

int DFS(int v){
    vis[v] = 1;
    ans++;
    for(auto u : g[v])
        if(!vis[u]) DFS(u);
    return ans;
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(cin >> n >> m, n){
        memset(g, 0, sizeof(g));
        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < m; i++){
            cin >> a;
            vector<int> v(a);
            for(int j = 0; j < a; j++)
                cin >> v[j];
            
            for(int j = 0; j < a; j++){
                for(int k = 0; k < a; k++){
                    if(j != k){
                        g[v[j]].push_back(v[k]);
                        g[v[k]].push_back(v[j]);
                    }
                }
            }
        }
        ans = 0;
        cout << DFS(0) << endl;
    }
    return 0;
}