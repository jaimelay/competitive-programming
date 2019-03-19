#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, x, cont = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        cont += --x;
    }
    cout << cont << endl;
    return 0;
}