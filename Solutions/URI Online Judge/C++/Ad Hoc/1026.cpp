#include <bits/stdc++.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long a, b;
    while(cin >> a >> b){
        cout << (a^b) << endl;
    }
    return 0;
}