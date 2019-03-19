#include <bits/stdc++.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int ct;
    while(ct--){
        int n, m;
        vector<bool> v(n, 1);
        for(int i = n - m; i >= 0; i -= m){
            if(v[i] == 0) continue;
            else v[i] = 0;
        }
    }
    return 0;
}