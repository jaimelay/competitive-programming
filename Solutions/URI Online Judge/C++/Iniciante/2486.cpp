#include <iostream>
#include <string>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n, soma = 0;
    string comida;
    while(1){
        cin >> t;
        if(t == 0) break;
        while(t--){
            cin >> n;
            cin.ignore();
            getline(cin, comida);
            if(comida == "suco de laranja") soma += n * 120;
            else if(comida == "morango fresco" || comida == "mamao") soma += n * 85;
            else if(comida == "goiaba vermelha") soma += n * 70;
            else if(comida == "manga") soma += n * 56;
            else if(comida == "laranja") soma += n * 50;
            else if(comida == "brocolis") soma += n * 34;
        }
        if(soma > 130) cout << "Menos " << soma - 130 << " mg" << endl;
        else if(soma < 110) cout << "Mais " << 110 - soma << " mg" << endl;
        else cout << soma << " mg" << endl;
        soma = 0;
    }
    return 0;
}