#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int fib[1001], cont = 0;

long long fibo(int n){
    cont++;
    if(n == 0 || n == 1) return n;
    else return fib[n] = fibo(n - 1) + fibo(n - 2);
    
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ct, n;
    cin >> ct;
    while(ct--){
        cin >> n;
        cout << "fib(" << n << ") = " << cont - 1 << " calls = " << fibo(n) << endl;
        cont = 0;
    }
    
    return 0;
}