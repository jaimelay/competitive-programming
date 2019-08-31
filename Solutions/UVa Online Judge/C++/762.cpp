#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

int m, dist[MAXN];
string a, b, src, dest, tmp;
map<string, int> cities;
map<int, string> id;
vector<int> g[MAXN];
vector<pair<int, int>> path;

bool BFS(int src, int dest){
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : g[v]){
            if(dist[u] == -1){
                if(u == dest){
                    path.push_back({v, dest});
                    return true;
                }else{
                    dist[u] = dist[v] + 1;
                    path.push_back({v, u});
                    q.push(u);
                }
            }
        }
    }
    return false;
}

void init(){
    memset(dist, -1, sizeof(dist));
    memset(g, 0, sizeof(g));
    cities.clear();
    id.clear();
    path.clear();
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int aux = 0;
    while(cin >> m){
        init();
        if(aux) cout << endl;
        int cont = 0;
        for(int i = 1; i <= m; i++){
            cin >> a >> b;
            if(!cities.count(a)){
                cities[a] = ++cont;
                id[cont] = a;
            } 
            if(!cities.count(b)){
                cities[b] = ++cont;
                id[cont] = b;
            }
            g[cities[a]].push_back(cities[b]);
            g[cities[b]].push_back(cities[a]);
        }
        cin >> src >> dest;
        getline(cin, tmp);
        cin.ignore();
        if(BFS(cities[src], cities[dest])){
            for(auto i : path) cout << id[i.first] << " " << id[i.second] << endl;
        }else{
            cout << "No route" << endl;
        }
        aux++;
    }
    return 0;
}