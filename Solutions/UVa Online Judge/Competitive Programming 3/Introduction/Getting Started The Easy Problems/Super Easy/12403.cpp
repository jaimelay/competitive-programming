#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t, money, ans = 0;
    string op;
    cin >> t;
    while(t--){
        cin >> op;
        if(op == "donate"){
            cin >> money;
            ans += money;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}