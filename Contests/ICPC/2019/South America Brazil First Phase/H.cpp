#include <bits/stdc++.h>

using namespace std;

int main(void){
    int v, n;

    cin >> v >> n;
    for(int i = 1; i < 10; i++) cout << (v * n * i - 1)/10 + 1 << " \n"[i == 9];
    
    return 0;
}