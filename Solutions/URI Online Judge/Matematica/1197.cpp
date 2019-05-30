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

    int v, t;
    while(scanf("%d %d", &v, &t) != EOF){
        int ans = v * t * 2;
        printf("%d\n", ans);
    }
    
    return 0;
}