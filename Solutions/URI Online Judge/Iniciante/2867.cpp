#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int t, n, m;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        cout << floor(((int)m * log10(n)) + 1) << endl;
    }
    return 0;
}