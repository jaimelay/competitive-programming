#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string w;
    int ct = 0;
    while(cin >> w){
        if(w == "#") break;
        cout << "Case " << ++ct << ": ";
        if(w == "HELLO") cout << "ENGLISH" << endl;
        else if(w == "HOLA") cout << "SPANISH" << endl;
        else if(w == "HALLO") cout << "GERMAN" << endl;
        else if(w == "BONJOUR") cout << "FRENCH" << endl;
        else if(w == "CIAO") cout << "ITALIAN" << endl;
        else if(w == "ZDRAVSTVUJTE") cout << "RUSSIAN" << endl;
        else cout << "UNKNOWN" << endl;
    }
    return 0;
}