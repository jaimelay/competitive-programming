#include <bits/stdc++.h>

using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    int t;

    while(cin >> t, t){
        cin >> s;
        int x = -1, y = -1, ans = INT_MAX;
        for(int i = 0; i < t; i++){
            if(s[i] == 'Z'){
                ans = 0;
                break;
            }
            if(s[i] == 'R') x = i;
            if(s[i] == 'D') y = i;
            if(x != -1 && y != -1) ans = min(ans, abs(x - y));
        }
        cout << ans << endl;
    }
    return 0;
}