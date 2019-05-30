#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, competidor;
    vector<int> competidores;
    multiset<int> classificados;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> competidor;
        competidores.push_back(competidor);
    }
    sort(competidores.begin(), competidores.end());
    int cont = 0;
    while(cont < k){
        classificados.insert(competidores.back());
        competidores.pop_back();
        cont++;
    }
    for(auto i : competidores)
        if(classificados.count(i) >= 1)
            cont++;

    cout << cont << endl;
    return 0;
}