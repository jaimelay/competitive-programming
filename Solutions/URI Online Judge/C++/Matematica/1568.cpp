#include <iostream>
#include <cmath>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    long long int n;
    double x;
    while(cin >> n){
        long long int cont = 1;
        long long int i = 1;
        long long int den = 2;
        long long int soma = 2;
        while(i <= sqrt(n)){
            x = (double)(n - i)/den;
            if(x == (long long int)x && x != 0) cont++;
            den++;
            i += soma;
            soma++;
        }
        cout << cont << endl;
    }
    return 0;
}