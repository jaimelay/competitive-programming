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

    int c, n, nota, soma, cont;
    float media;
    cin >> c;
    while(c--){
        cin >> n;
        vector<int> notas;
        for(int i = 0; i < n; i++){
            cin >> nota;
            notas.push_back(nota);
        }
        soma = 0, media = 0, cont = 0;
        soma = accumulate(notas.begin(), notas.end(), 0);
        media = soma/n;
        for(auto i : notas)
            if(i > media)
                cont++;
        float percent = (float)cont/n * 100;
        printf("%.3f%%\n", percent);
    }
    return 0;
}