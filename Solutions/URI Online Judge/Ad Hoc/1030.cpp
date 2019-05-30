#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

int josephus(int n, int k){
    int m = 0;
    for(int i = 1; i <= n; i++)
        m = (m + k) % i;
    return m;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ct, n, k;

    scanf("%d", &ct);
    for(int i = 1; i <= ct; i++){
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i, josephus(n, k) + 1);
    }

    return 0;
}