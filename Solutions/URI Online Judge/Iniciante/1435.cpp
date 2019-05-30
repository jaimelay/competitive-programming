#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int n, mat[100][100] = { 0 };
    while(cin >> n){
        if(n == 0) break;
        memset(mat, 0, sizeof(mat));
        int valor = 1;
        int inicio = 0;
        int fim = n;
        int centro = mat[valor - 1][valor - 1];
        while(centro == 0){
            for(int i = inicio; i < fim; i++){
                mat[inicio][i] = valor;
                mat[i][inicio] = valor;
                if(mat[fim - 1][i] == 0 && mat[i][fim - 1] == 0){
                    mat[fim - 1][i] = valor;
                    mat[i][fim - 1] = valor;
                }else{
                    break;
                }
            }
            valor++;
            centro = mat[valor - 1][valor - 1];
            inicio = valor - 1;
            fim--;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j > 0) cout << right << setw(4) << mat[i][j]; 
                else cout << right << setw(3) << mat[i][j]; 
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}