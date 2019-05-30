#include <bits/stdc++.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int ct, n, cap, r;
    cin >> ct;
    while(ct--){
        cin >> n;
        
        int poder[n + 1], peso[n + 1];
        memset(poder, 0, sizeof(poder));
        memset(peso, 0, sizeof(peso));
        for(int i = 1; i <= n; i++)
            cin >> poder[i] >> peso[i];

        cin >> cap;
        cin >> r;
        int dp[n + 1][cap + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= cap; j++){
                if(peso[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(poder[i] + dp[i - 1][j - peso[i]], dp[i - 1][j]);
            }
        }
        if(dp[n][cap] >= r) cout << "Missao completada com sucesso" << endl;
        else cout << "Falha na missao" << endl;
    }
    return 0;
}