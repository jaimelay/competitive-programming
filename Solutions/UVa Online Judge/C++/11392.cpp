// Solução: Adicionando '3' e marcando os restos até achar
// algum repetido. 
// Se achou só ir retirando os '3' e testando até o resto dar 0.
// Exemplo:
// 3 = 3 (mod 4)
// 33 = 1 (mod 4)
// 333 = 1 (mod 4)
// 330 = 2 (mod 4)
// 300 = 0 (mod 4)

#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

ll k, qntd3, qntd0, resto;
vector<ll> restos;

bool isRepeated(int resto){
    restos[resto]++;
    return restos[resto] > 1 ? true : false;
}

int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> k){
        restos.assign(k, 0);
        qntd3 = 1, qntd0 = 0, resto = 3 % k;
        while(resto != 0){
            if(isRepeated(resto)) break;
            qntd3++;
            resto = ((resto * 10) + 3) % k;
        }

        for(int i = 0; i < k; i++){
            if(abs(resto) % k == 0){
                cout << qntd3 + qntd0 << " " << qntd3 << " " << qntd0 << endl;
                break; 
            }
            resto -= (3 * pow(10, i));
            qntd3--;
            qntd0++;
        }
    }
    return 0;
}