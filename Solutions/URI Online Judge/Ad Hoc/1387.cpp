#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        cout << a + b << endl;
    }
    return 0;
}