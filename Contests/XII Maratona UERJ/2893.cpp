#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    int t, k, n, cont;
    long long int soma = 0;

    queue<int> fila;

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> k >> n;
        if(n < k){
            cout << n - 1 << endl;
        }else{
            for(int i = 0; i < k; i++){
                fila.push(i);
            }

            soma = ( fila.back() * k )/2;
            fila.push(soma % 1000007);

            cont = n - k;

            fila.pop();
            for(int i = 0; i < cont - 1; i++){
                soma = 0;
                for(int j = 0; j < k; j++){
                    soma += fila.front();
                    fila.push(fila.front());
                    fila.pop();
                }
                fila.push(soma % 1000007);
                fila.pop();
            }
    
            cout << fila.back() % 1000007 << endl;

            while(!fila.empty()) fila.pop();
            soma = 0;
        }
    }
    return 0;
}
