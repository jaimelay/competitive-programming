#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c[50] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char s;
    while(scanf("%c", &s) != EOF){
        for(int i = 0; i < 50; i++)
            if(s == c[i]){
                printf("%c", c[i - 1]);
                break;
            }else if(s == ' '){
                printf(" ");
                break;
            }else if(s == '\n'){
                printf("\n");
                break;
            }
    }
    return 0;
}