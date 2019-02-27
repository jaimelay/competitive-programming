#include <iostream>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i + j == n - 1) cout << 2;
                else if(i == j) cout << 1;
                else cout << 3;
            }
            cout << endl;
        }
    }
    return 0;
}