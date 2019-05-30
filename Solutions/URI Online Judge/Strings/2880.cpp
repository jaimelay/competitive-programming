#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string mensagem, crib;
    cin >> mensagem;
    cin >> crib;

    int cont = 0, ans = 0;
    for(int i = 0; i < mensagem.size() - crib.size() + 1; i++){
        for(int j = 0; j < crib.size(); j++){
            if(mensagem[i + j] != crib[j])
                cont++;
        }
        if(cont == crib.size()) ans++;
        cont = 0;
    }
    printf("%d\n", ans);
    return 0;
}