#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, bobo, x;
    bool eleito = true;

    cin >> n;
    cin >> bobo;
    for(int i = 1; i < n; i++){
        cin >> x;
        if(x > bobo) eleito = false;
    }
    cout << (eleito ? "S":"N") << endl;

    return 0;
}