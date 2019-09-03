#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

vector<pair<int, int>> v[35];
int k, b, input;
int vis[MAXN], E[MAXN][MAXN], dist[MAXN], maior;

vector<int> topSort, maiorCaminho;

void DFS(int p, int v){
    vis[v] = 1;
    for(int u = 0; u <= k + 1; u++){
        if(E[v][u]){
            if(!vis[u]) DFS(v, u);
            dist[v] = max(dist[v], dist[u] + 1);
        }
    }
    maior = max(maior, dist[v]);
    topSort.push_back(v);
}

void longest_path(int v){
    maiorCaminho.push_back(v);
    for(int u = 0; u <= k + 1; u++){
        if(E[v][u]){
            if(dist[u] == (dist[v] - 1)){
                longest_path(u);
                break;
            }
        }
    }
}

void init(){
	memset(v, 0, sizeof(v));	
	memset(E, 0, sizeof(E));	
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    topSort.clear();
    maiorCaminho.clear();
    maior = 0;
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	while(cin >> k >> b){
		init();
		for(int i = 1; i <= k; i++){
			for(int j = 0; j < b; j++){
				cin >> input;
				v[i].push_back({ input, i });
			}
		}

		for(int i = 1; i <= k; i++) sort(v[i].begin(), v[i].end());
        sort(v, v + k + 1);

		for(int i = 1; i <= k; i++){
			for(int j = i + 1; j <= k; j++){
                int flag = 0, p, q;
				for(int x = 0; x < b; x++){
                    p = v[i][x].second, q = v[j][x].second;
					if(v[i][x].first < v[j][x].first) flag++;
                    else break;
				}
                if(flag == b) E[q][p] = 1;
			}
		}

        for(int i = 1; i <= k; i++) E[0][i] = 1;
        for(int i = 1; i <= k; i++) E[i][k + 1] = 1;

        for(int i = 0; i <= k + 1; i++)
            if(!vis[i]) DFS(i, i);
        
        reverse(topSort.begin(), topSort.end());

        for(int i = 0; i <= k + 1; i++){
            if(dist[i] == maior){
                longest_path(i);
            }
        }

        reverse(maiorCaminho.begin(), maiorCaminho.end());
        cout << maiorCaminho.size() - 2 << endl;
        for(int i = 1; i < maiorCaminho.size() - 1; i++){
            cout << maiorCaminho[i] << (i != maiorCaminho.size() - 2 ? " ": "");
        }
        cout << endl;
	}
	return 0;
}