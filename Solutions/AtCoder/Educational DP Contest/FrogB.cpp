#include <bits/stdc++.h>

using namespace std;

int n, k, h[1000001], dp[1000001];

int main(void){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> h[i];

    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = INT_MAX;
        for(int j = 1; j <= k && i - j >= 0; j++){
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}