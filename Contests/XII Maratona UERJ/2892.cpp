#include <bits/stdc++.h>

using namespace std;

int D[1000001];

int mmc(int a, int b){
    long long c = a, d = b;
    return c*d/__gcd(c, d);
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, a, b;
    while(cin >> t >> a >> b){
        if(t == 0 && a == 0 && b == 0) break;
        int aux = mmc(a,b);
        int nd = 0;

        for(int i = 1; i < t; i++)
            if(t % i == 0)
                D[nd++] = i;

        for(int i = 0; i < nd; i++)
        	if(mmc(D[i], aux) == t)
                cout << D[i] << " ";
        cout << t << endl;
    }
    return 0;
}