#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI acos(-1)

int main(void){
    ios_base::sync_with_stdio(false);

    double f;
    while(cin >> f){
        double ladoQuadrado = (f * (sin((108*PI)/180))/sin((63*PI)/180));
        cout << fixed << setprecision(10);
        cout << ladoQuadrado << endl;
    }
    return 0;
}