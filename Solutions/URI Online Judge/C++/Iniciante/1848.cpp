#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    int cont = 0, valor = 0;
    string s;
    while(cont < 3){
        getline(cin, s);
        if(s == "---")
            valor += 0;
        else if(s == "--*")
            valor += 1;
        else if(s == "-*-")
            valor += 2;
        else if(s == "-**")
            valor += 3;
        else if(s == "*--")
            valor += 4;
        else if(s == "*-*")
            valor += 5;
        else if(s == "**-")
            valor += 6;
        else if(s == "***")
            valor += 7;
        else if(s == "caw caw"){
            cont++;
            cout << valor << endl;
            valor = 0;
        }
    }
    return 0;
}