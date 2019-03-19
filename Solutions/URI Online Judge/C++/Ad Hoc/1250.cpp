#include <bits/stdc++.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, t;
    string pulos;
    cin >> n;
    while(n--){
        cin >> t;
        int alturas[t], atingido = 0;
        for(int i = 0; i < t; i++){
            cin >> alturas[i];
        }
        cin >> pulos;
        for(int i = 0; i < t; i++){
            if(pulos[i] == 'J' && alturas[i] > 2) atingido++;
            else if(pulos[i] == 'S' && (alturas[i] == 1 || alturas[i] == 2)) atingido++;
        }
        cout << atingido << endl;
    }
    return 0;
}