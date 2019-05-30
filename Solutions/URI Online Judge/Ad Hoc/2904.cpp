#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int vet[1000001];

int main(void){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, soma;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> vet[i];
    }
    soma = accumulate(vet, vet + n, 0);

    long long i = 0, j = 0, diag = 0, s = vet[j], limite = n;
    while(j < n && i < limite){
        if(s == soma/2){
            diag++;
            s -= vet[i++];
            s += vet[++j];
            if(diag == 1){
                limite = j;
            }
        }else if(s > soma/2){
            s -= vet[i++];
        }else{
            s += vet[++j];
        }
    }
    if(diag > 1 && soma%2 == 0){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
    return 0;
}