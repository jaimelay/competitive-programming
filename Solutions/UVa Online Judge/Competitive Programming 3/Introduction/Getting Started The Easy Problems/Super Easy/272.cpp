#include <bits/stdc++.h>

using namespace std;

int main(void){
    char c;
    int cont = 0;
    while(scanf("%c", &c) != EOF){
        if(c == '"'){
            cont++;
            if(cont % 2) printf("``");
            else printf("''");
        }else{
            printf("%c", c);
        }
    }
    return 0;
}