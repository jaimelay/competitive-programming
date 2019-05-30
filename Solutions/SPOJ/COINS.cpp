#include <bits/stdc++.h>

using namespace std;

map<long long, long long> dp;

long long solve(long long n){
    if(dp.count(n) != 0) return dp[n];
    else return dp[n] = max(n, solve(n/2) + solve(n/3) + solve(n/4));
}

int main(void){
    long long n;
    while(cin >> n){
        cout << solve(n) << endl;
    }
    return 0;
}