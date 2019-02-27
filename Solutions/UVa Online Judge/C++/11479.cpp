#include <iostream>
#include <cmath>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    long int a, b, c;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> a >> b >> c;
        if(!(abs(b - c) < a && a < b + c) || !(abs(a - c) < b && b < a + c) || !(abs(a - b) < c && c < a + b)){
            cout << "Case " << i << ": Invalid" << endl;
        }else{
            if(a != b && a != c && b != c){
                cout << "Case " << i << ": Scalene" << endl;
            }else if(a == b && b == c){
                cout << "Case " << i << ": Equilateral" << endl;
            }else{
                cout << "Case " << i << ": Isosceles" << endl;
            }
        }
    }
    return 0;
}