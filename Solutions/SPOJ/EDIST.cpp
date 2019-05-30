#include <bits/stdc++.h>

using namespace std;

int dp[3000][3000];
string a, b;

int edist(int n, int m){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min({dp[i - 1][j],
                                    dp[i][j - 1],
                                    dp[i - 1][j - 1]});
        }
    }
    return dp[n][m];
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> a >> b;
        cout << edist(a.size(), b.size()) << endl;
    }
    return 0;
}