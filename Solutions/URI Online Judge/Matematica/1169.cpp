#include <bits/stdc++.h>

using namespace std;

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, x;
    cin >> t;
    while(t--){
        cin >> x;
        cout << (unsigned long long) (pow(2, x)/12000) << " kg" << endl;
    }
    return 0;
}