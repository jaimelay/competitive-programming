#include <bits/stdc++.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int ct, n, vet[2001] = { 0 };
    cin >> ct;
    while(ct--){
        cin >> n;
        vet[n]++;
    }
    for(int i = 1; i <= 2000; i++){
        if(vet[i] > 0) cout << i << " aparece " << vet[i] << " vez(es)" << "\n";
    }
    return 0;
}