#include <bits/stdc++.h>

using namespace std;

int n, c, a, b, t, media, maior = 0, vet[100010], soma[100010];

int contagem(){
    int i = 0, j = 1, cnt = 0, sum;
    while(j <= n){
        sum = soma[j] - soma[i];
        if((sum + t - 1)/t > media){
            cnt++;
            i = j - 1;
        }else{
            j++;
        }
    }
    if(soma[n] - soma[i] > 0) cnt++;
    return cnt;
}

int main(void){
    cin >> n >> c >> t;
    for(int i = 1; i <= n; i++){
        cin >> vet[i];
        soma[i] = soma[i - 1] + vet[i];
        maior = max(maior, vet[i]);
    }

    a = (maior + t - 1)/t;
    b = (soma[n] + t - 1)/t;
    while(a != b){
        media = (a + b)/2;
        int k = contagem();
        if(k > c) a = media + 1;
        else b = media;
    }
    
    cout << a << endl;

    return 0;
}