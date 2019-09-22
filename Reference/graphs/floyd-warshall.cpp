// Calcula os menores caminhos entre todos pares de vertices.

int dist[MAXN][MAXN]; // dist = graph, sem aresta = infinito ou 0 para fechamento transitivo.

for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            // dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]); // Fechamento Transitivo
        }
    }
}