#include <bits/stdc++.h>

using namespace std;

long long solve(vector<long long> v){
    int n = v.size();

    if(n == 0) return 0;
    if(n == 1) return v[0];
    if(n == 2) return max(v[0], v[1]);

    long long dp[n + 10];
    dp[0] = v[0];
    dp[1] = max(v[0], v[1]);

    for(int i = 2; i < n; i++)
        dp[i] = max(v[i] + dp[i - 2], dp[i - 1]);

    return dp[n - 1];
}

int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ct, n;
    cin >> ct;
    for(int i = 1; i <= ct; i++){
        cin >> n;
        vector<long long> monsters(n);
        for(int i = 0; i < n; i++) cin >> monsters[i];
        cout << "Case " << i << ": " << solve(monsters) << endl;
    }
    return 0;
}