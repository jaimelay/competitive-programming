#include <iostream>

using namespace std;

int main(void){
    int t, n, k;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> k;
        cout << n/k + n%k << endl;
    }
    return 0;
}
