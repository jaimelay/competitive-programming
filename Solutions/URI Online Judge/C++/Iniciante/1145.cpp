#include <iostream>

using namespace std;

int main(void){
    int x, y;
    cin >> x >> y;
    for(int i = 1; i <= y; i += x){
        for(int j = 0; j < x; j++){
            if(i + j > y) break;
            if(j == x - 1) cout << i + j;
            else cout << i + j << " ";
        }
        cout << endl;
    }
    return 0;
}