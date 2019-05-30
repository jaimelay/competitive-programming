#include <bits/stdc++.h>

using namespace std;

int dp[6000];

int main(void){
    // freopen("input.txt", "r", stdin);

    string n;
    while(cin >> n){
        memset(dp, 0, sizeof(dp));
        if(n == "0") break;
        dp[0] = 1;
        for(int i = 1; i < n.size(); i++){
            long long num = (n[i - 1] - '0') * 10 + (n[i] - '0');
            if(n[i] - '0') dp[i] = dp[i - 1];
            if(num >= 10 && num <= 26)
                dp[i] += dp[(i - 2) < 0 ? 0:i - 2];
        }
        cout << dp[n.size() - 1] << endl;
    }
    return 0;
}