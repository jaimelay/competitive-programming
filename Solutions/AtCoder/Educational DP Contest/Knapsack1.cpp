#include <bits/stdc++.h>

using namespace std;

int n, cap;
int w[110], v[110];
long long dp[1000001][110];

int main(void){
    freopen("input.txt", "r", stdin);
    cin >> n >> cap;
    int w[n + 1], v[n + 1];
    long long dp[cap + 1][n + 1];
    w[0] = 0;
    v[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= cap; i++) dp[i][0] = 0;
    for(int j = 0; j <= n; j++) dp[0][j] = 0;

    for(long long i = 1; i <= cap; i++){
        for(int j = 1; j <= n; j++){
            if(w[j] > i) dp[i][j] = dp[i][j - 1];
            else dp[i][j] = max(v[j] + dp[i - w[j]][j - 1], dp[i][j - 1]);
        }
    }
    cout << dp[cap][n] << endl;

    return 0;
}