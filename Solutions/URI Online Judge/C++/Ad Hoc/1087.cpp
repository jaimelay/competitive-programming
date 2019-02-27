#include <iostream>
#include <cmath>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> x2 >> y2){
        if(x1 == 0 && y2 == 0 && x2 == 0 && y2 == 0) break;
        if(x1 == x2 && y1 == y2){
            cout << 0 << endl;
        }else if(x1 == x2 || y1 == y2){
            cout << 1 << endl;
        }else if(abs(x1 - x2) == abs(y1 - y2)){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }
    return 0;
}