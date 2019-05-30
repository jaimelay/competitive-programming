#include <iostream>

using namespace std;

int main(void){
    int a, b, q, r;
    cin >> a >> b;

    if(a < 0){
        for(r = 0; r < abs(b); r++){
            if((a - r) % b == 0){
                q = (a - r)/b;
                break;
            } 
        }
    }else{
        q = a / b;
        r = a % b;
    }

    cout << q << " " << r << endl;

    return 0;
}