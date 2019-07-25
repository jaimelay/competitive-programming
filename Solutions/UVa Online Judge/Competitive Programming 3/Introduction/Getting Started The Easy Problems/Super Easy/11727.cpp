#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, v[3];
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> v[0] >> v[1] >> v[2];
        sort(v, v + 3);
        cout << "Case " << i << ": " << v[1] << endl;
    } 
    return 0;
}