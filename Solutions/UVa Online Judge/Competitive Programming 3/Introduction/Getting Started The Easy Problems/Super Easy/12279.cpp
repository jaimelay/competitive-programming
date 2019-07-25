#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, ct = 0;
    while(cin >> n){
        if(n == 0) break;
        int given = 0, supossed = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(x == 0) given++;
            else supossed++;
        }
        cout << "Case " << ++ct << ": " << supossed - given << endl;
    }
    return 0;
}