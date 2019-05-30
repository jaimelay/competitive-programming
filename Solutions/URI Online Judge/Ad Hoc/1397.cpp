#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    while(scanf("%d", &n)){
        if(n == 0) break;
        int contA = 0, contB = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &a, &b);
            if(a > b) contA++;
            else if(a < b) contB++;
        }
        printf("%d %d\n", contA, contB);
    }
    return 0;
}