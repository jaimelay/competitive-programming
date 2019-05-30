#include <bits/stdc++.h>

using namespace std;

int main(void){
    int aux = 0, input;
    int cres = 0, decres = 0, nada = 0;
    for(int i = 0; i < 5; i++){
        cin >> input;
        if(aux == 0){
            aux = input;
        }else{
            if(input > aux){
                if(decres > 0){
                    cout << "N" << endl;
                    break;
                }else{
                    cres++;
                }
            }else if(input < aux){
                if(cres > 0){
                    cout << "N" << endl;
                    break;
                }else{
                    decres++;
                }
            }
            aux = input;
        }
    }
    if(cres == 4) cout << "C" << endl;
    else if(decres == 4) cout << "D" << endl;
    return 0;
}