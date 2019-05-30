#include <bits/stdc++.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<long long> estrelas(n);
    vector<bool> visitados(n, false);

    for(auto &i : estrelas) 
        cin >> i;

    int j = 0;
    int cont = 0;
    while(j >= 0 && j < n){
        if(!visitados[j]){
            cont++;
            visitados[j] = true;
        }
        if(!estrelas[j]) break;
        if(estrelas[j] % 2 == 0){
            estrelas[j]--;
            j--;
        }else if(estrelas[j] % 2 != 0){
            estrelas[j]--;
            j++;
        } 
    }

    long long soma = accumulate(estrelas.begin(), estrelas.end(), 0LL);
    cout << cont << " " << soma << endl;
    return 0;
}