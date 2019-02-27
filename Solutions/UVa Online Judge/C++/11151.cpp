#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int x, tamanho;
    string palavra;
    cin >> x;
    for(int i = 0; i < x; i++){
        cin >> palavra;
        if(palavra == string(palavra.rbegin(), palavra.rend())) {
            tamanho = palavra.size();
        }else{
            while(palavra != string(palavra.rbegin(), palavra.rend()) || palavra.size() == 0){
                palavra.pop_back();
            }
            tamanho = palavra.size();
        }
        cout << tamanho << endl;
    }

    return 0;
}