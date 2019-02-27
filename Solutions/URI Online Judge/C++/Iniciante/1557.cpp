#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    
    int n;
    while(cin >> n){
        if(n == 0) break;
        long int mat[n][n];
        for(int i = 0; i < n; i++){
            int cont = pow(2, i);
            for(int j = 0; j < n; j++){
                mat[i][j] = cont;
                cont *= 2;
            }
        }
        long long int maior = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] > maior) maior = mat[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j > 0){
                    if(maior % 10 == maior) cout << right << setw(2) << mat[i][j];
                    else if(maior % 100 == maior) cout << right << setw(3) << mat[i][j];
                    else if(maior % 1000 == maior) cout << right << setw(4) << mat[i][j];
                    else if(maior % 10000 == maior) cout << right << setw(5) << mat[i][j];
                    else if(maior % 100000 == maior) cout << right << setw(6) << mat[i][j];
                    else if(maior % 1000000 == maior) cout << right << setw(7) << mat[i][j];
                    else if(maior % 10000000 == maior) cout << right << setw(8) << mat[i][j];
                    else if(maior % 100000000 == maior) cout << right << setw(9) << mat[i][j];
                    else if(maior % 1000000000 == maior) cout << right << setw(10) << mat[i][j];
                }else{
                    if(maior % 10 == maior) cout << right << setw(1) << mat[i][j];
                    else if(maior % 100 == maior) cout << right << setw(2) << mat[i][j];
                    else if(maior % 1000 == maior) cout << right << setw(3) << mat[i][j];
                    else if(maior % 10000 == maior) cout << right << setw(4) << mat[i][j];
                    else if(maior % 100000 == maior) cout << right << setw(5) << mat[i][j];
                    else if(maior % 1000000 == maior) cout << right << setw(6) << mat[i][j];
                    else if(maior % 10000000 == maior) cout << right << setw(7) << mat[i][j];
                    else if(maior % 100000000 == maior) cout << right << setw(8) << mat[i][j];
                    else if(maior % 1000000000 == maior) cout << right << setw(9) << mat[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}