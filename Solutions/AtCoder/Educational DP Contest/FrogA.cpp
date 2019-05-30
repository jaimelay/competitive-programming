#include <bits/stdc++.h>

using namespace std;

int n, h[1000001], dp[1000001];

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];

    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]), dp[i - 1] + abs(h[i] - h[i - 1]));
    }
    cout << dp[n - 1] << endl;
    return 0;
}