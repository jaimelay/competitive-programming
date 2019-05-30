#include <iostream>

using namespace std;

long long int fat(int n){
    long long int memo[20];
    if(n >= 0){
        memo[0] = 1;
        for(int i = 1; i <= n; i++){
            memo[i] = i * memo[i - 1];
        }
        return memo[n];
    }
}

int main(void){
    int m, n;
    while(cin >> m >> n){
        cout << fat(m) + fat(n) << endl;
    }
    return 0;
}