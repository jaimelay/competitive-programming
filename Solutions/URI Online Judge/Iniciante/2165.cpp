#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    string texto;
    getline(cin, texto);
    if(texto.size() <= 140) cout << "TWEET" << endl;
    else cout << "MUTE" << endl;

    return 0;
}