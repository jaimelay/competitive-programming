#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

int vis[MAXN], n;
vector<int> g[MAXN];
map<string, int> m;
string a, b;

void DFS(int v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(vis[u] == 0){
            DFS(u);
            if(vis[u] == 1) vis[v] = 2;
        }
    }
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(cin >> n, n != 0){
        m.clear();
        memset(g, 0, sizeof(g));
        memset(vis, 0, sizeof(vis));

        int p = 0;
        cin >> a;
        if(m.count(a) == 0) m[a] = ++p;
        for(int i = 1; i < n; i++){
            cin >> a >> b;
            if(m.count(a) == 0) m[a] = ++p;
            if(m.count(b) == 0) m[b] = ++p;
            g[m[a]].push_back(m[b]);
            g[m[b]].push_back(m[a]);
        }
        
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0) DFS(i);
        }

        int cont = 0;
        bool flag = true;
        for(int i = 1; i <= n; i++){
            if(vis[i] == 2){
                int cont2 = 0;
                for(auto v : g[i]){
                    if(vis[v] == 1){
                        cont2++;
                        if(cont2 > 1) break;
                    }
                }
                if(cont2 == 1) flag = false;
                cont++;
            }
        }

        cout << n - cont << " " << (flag ? "Yes":"No") << endl;
    }
    return 0;
}
