#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);

    int l, c, r1, r2;
    while(cin >> l >> c >> r1 >> r2){
        if(l == 0 && c == 0 && r1 == 0 && r2 == 0) break;

        int diametroC1 = 2 * r1;
        int diametroC2 = 2 * r2;
        int diagonal = sqrt(pow(l,2) + pow(c,2));

        if(diametroC1 > l || diametroC1 > c || diametroC2 > l || diametroC2 > c){
            cout << "N" << endl;
        }else{
            int xc1 = r1;
            int yc1 = c - r1;
            int xc2 = l - r2;
            int yc2 = r2;

            if(r1 + r2 <= sqrt(pow((xc1 - xc2),2) + pow((yc1 - yc2),2))) cout << "S" << endl;
            else cout << "N" << endl;
        }
    }
    return 0;
}