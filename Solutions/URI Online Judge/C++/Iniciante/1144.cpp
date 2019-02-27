#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x = i * i;
        cout << i << " " << x << " " << i * x << endl;
        cout << i << " " << x + 1 << " " << (i * x) + 1 << endl;
    }
    return 0;
}