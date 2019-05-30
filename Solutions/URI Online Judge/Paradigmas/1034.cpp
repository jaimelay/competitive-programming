#include <bits/stdc++.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n, m, a, input;
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        int pd[m + 1];
        int blocos[n];

        memset(pd, 999999, sizeof(pd));
        pd[0] = 0;
        for(int i = 0; i < n; i++) cin >> blocos[i];

        for(int i = 0; i < n; i++){
            int k = blocos[i];
            for(int j = k; j <= m; j++){
                pd[j] = min(pd[j], 1 + pd[j - blocos[i]]);
            }
        }

        cout << pd[m] << endl;
    }
    return 0;
}