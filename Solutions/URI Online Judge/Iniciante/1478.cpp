#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void){
    int a, i, j, cont=a-1;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    while(true){
        cin>>a;
        if(a==0) return 0;
        if(a==1){
            cout << "  "<< 1 << endl;
            cout << endl;
        }else{
            int matriz[a][a];
            for(i=0; i<a; i++){
                for(j=0; j<a; j++){
                    if(i==j){
                        matriz[i][j]=1;
                    }else if(i>j){
                        matriz[i][j]=i-j+1;
                    }else if(j>i){
                        matriz[i][j]=j-i+1;
                    }
                }
            }

            for(i = 0; i < a; i++){
                for(j = 0; j < a; j++){
                    if(j > 0) cout << right << setw(4) << matriz[i][j]; 
                    else cout << right << setw(3) << matriz[i][j]; 
                }
                cout << endl;
            }
            cout << endl;
        }
    } 
} 