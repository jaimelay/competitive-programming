#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    
    int n;
    string frase = "LIFE IS NOT A PROBLEM TO BE SOLVED";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << frase[i];
    }
    cout << endl;
    return 0;
}