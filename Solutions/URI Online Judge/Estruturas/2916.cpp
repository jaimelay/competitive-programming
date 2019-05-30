#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    long long int n, k, x, soma = 0;
    long long int *v;

    while(cin >> n >> k){
        v = (long long int*) calloc (n,sizeof(long long int));
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v, v + n);
        while(k--){
            soma += v[n - 1] % 1000000007;
            n--;
        }
        cout << soma % 1000000007 << endl;
        soma = 0;
        free(v);
    }

    return 0;
}