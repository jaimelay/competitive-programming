#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

int n, a, b, vis[MAXN];
vector<int> g[MAXN];

void DFS(int v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(!vis[u]){
            DFS(u);
            if(vis[u] == 1) vis[v] = 2;
        }
    }
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(cin >> n, n){
        memset(g, 0, sizeof(g));
        memset(vis, 0, sizeof(vis));

        bool flag = false;
        for(int line = 1; line <= n; line++){
            cin >> a;
            if(a == 0) flag = true;
            while(a--){
                cin >> b;
                g[line].push_back(b);
            }
        }

        for(int i = 1; i <= n; i++)
            if(!vis[i]) DFS(i);
        
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(vis[i] == 2) ans++;

        if(flag) cout << 1 << endl;
        else cout << ans << endl;
    }
    return 0;
}