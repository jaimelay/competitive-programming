#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(void){
    int t, letras[26], maior = 0;
    string texto;
    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin, texto);
        for(int i = 0; i < 26; i++)
            letras[i] = 0;

        for(int i = 0; i < texto.size(); i++)
            letras[tolower(texto[i]) - 'a'] += 1;

        for(int i = 0; i < 26; i++)
            if(letras[i] > maior) maior = letras[i];

        for(int i = 0; i < 26; i++)
            if(letras[i] == maior) printf("%c", i + 'a');
        printf("\n");

        texto.clear();
        maior = 0;
    }
    return 0;
}