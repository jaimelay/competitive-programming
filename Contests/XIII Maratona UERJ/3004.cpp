#include <bits/stdc++.h>

using namespace std;

int main(void){
    int q, a, b, c, d;

    cin >> q;
    while(q--){
        cin >> a >> b >> c >> d;
        
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);

        if(a < c && b < d) cout << "S" << endl;
        else cout << "N" << endl;
    }
    return 0;
}