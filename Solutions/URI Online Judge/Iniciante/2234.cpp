#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int main(void){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, p;
    float ans;
    scanf("%d %d", &h, &p);
    ans = (float)h/p;
    printf("%.2f\n", ans);
    return 0;
}