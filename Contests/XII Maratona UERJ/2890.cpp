#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, ans;
    while(scanf("%lld", &n)){
        if(n == 0) break;
        ans = ((n*n*n*n) + 11*n*n)/12;
        printf("%lld\n", ans % 1000007);
    }
    return 0;
}