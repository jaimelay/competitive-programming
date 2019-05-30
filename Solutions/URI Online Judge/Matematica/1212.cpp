#include <iostream>

#define endl '\n'

using namespace std;

unsigned long findCarry(unsigned long a, unsigned long b){
    unsigned long x, y, c, op;
    c = 0;
    op = 0;
    while(1){
        x = a % 10;
        y = b % 10;
        a = a/10;
        b = b/10;
        if((x + y + c) >= 10){
            op++;
            c = 1;
        }else
            c = 0;
        if(a == 0 && b == 0) break;
    }
    return op;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long a, b, op;
    while(scanf("%ld %ld", &a, &b)){
        if(a == 0 && b == 0) break;
        op = findCarry(a, b);
        if(op == 0) printf("No carry operation.\n");
        else if(op == 1) printf("1 carry operation.\n");
        else printf("%ld carry operations.\n", op);
    }
    return 0;
}
