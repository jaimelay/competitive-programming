#include <bits/stdc++.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    while(cin >> n && n){
        int cont = 0, cont2 = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(x == 0) cont++;
            else cont2++;
        }
        cout << "Mary won " << cont << " times and John won " << cont2 << " times" << endl;
    }
    return 0;
}