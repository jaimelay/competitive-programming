#include <bits/stdc++.h>

using namespace std;

int main(void){
    int q, a, b, c, d, e, f;
    
    cin >> q;
    while(q--){
        vector<int> b1(3), b2(3);

        cin >> b1[0] >> b1[1] >> b1[2] >> b2[0] >> b2[1] >> b2[2];

        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());

        if( (b1[1] > b2[0] && b1[2] > b2[1]) && (b2[1] > b1[0] && b2[2] > b1[1]) ) cout << 3 << endl;
        else if( (b1[1] > b2[0] && b1[2] > b2[1]) && !(b2[1] > b1[0] && b2[2] > b1[1]) ) cout << 2 << endl;
        else if( !(b1[1] > b2[0] && b1[2] > b2[1]) && (b2[1] > b1[0] && b2[2] > b1[1]) ) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}