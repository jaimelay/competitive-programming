//
// https://www.urionlinejudge.com.br/judge/pt/problems/view/1527
//

#include <bits/stdc++.h>

using namespace std;

int pai[1000001];

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

int main(void){
    int n = 5;
    for(int i = 1; i <= n; i++) pai[i] = i; // Inicializar vetor pai.

    return 0;
}