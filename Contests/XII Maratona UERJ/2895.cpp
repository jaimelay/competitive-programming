#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;

        int ans = INT_MAX;
        
        for(int i = n; i < (1 << 12); i++)
            ans = min(ans, __builtin_popcount(i) + __builtin_popcount(i - n));
        cout << ans << endl;
    }
    return 0;
}
