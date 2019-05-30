#include <bits/stdc++.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int ct;
    bool newline = false;
    while(cin >> ct && ct){
        int maior = 0;
        string palavras[ct];
        for(int i = 0; i < ct; i++){
            cin >> palavras[i];
            int aux = palavras[i].size();
            maior = max(maior, aux);
        }

        if(!newline) newline = true;
        else cout << endl;

        for(int i = 0; i < ct; i++){
            cout << setw(maior) << palavras[i] << endl;
        }
    }
    return 0;
}