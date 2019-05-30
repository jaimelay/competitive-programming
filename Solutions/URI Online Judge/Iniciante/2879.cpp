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

    int n, porta, ans = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &porta);
        if(porta == 2 || porta == 3) ans++;
    }
    printf("%d\n", ans);
    return 0;
}