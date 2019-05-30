#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    float c;
    cin >> n;
    while(n--){
        cin >> c;
        int dias = 0;
        while(c > 1.0){
            c /= 2;
            dias++;
        }
        cout << dias << " dias" << endl;
    }
    return 0;
}