#include <bits/stdc++.h>

using namespace std;

int main(void){
    string w;
    int ct = 0;
    while(cin >> w){
        if(w == "*") break;
        cout << "Case " << ++ct << ": ";
        if(w == "Hajj") cout << "Hajj-e-Akbar" << endl;
        else cout << "Hajj-e-Asghar" << endl;
    }
    return 0;
}