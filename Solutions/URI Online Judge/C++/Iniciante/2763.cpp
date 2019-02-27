#include <bits/stdc++.h>

using namespace std;

int main(void){
    string cpf;
    getline(cin, cpf);
    for(auto i : cpf){
        if(i >= '0' && i <= '9') cout << i;
        else cout << endl;
    }
    cout << endl;
    return 0;
}