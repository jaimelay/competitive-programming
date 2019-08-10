#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

char S[101][51];
int P[101], C[101];
int n, m, M, x;
int cont = 0;

int contInv(int i){
    cont = 0;
    for(int j = 0; j <= n - 2; j++){
        for(int k = j + 1; k <= n - 1; k++){
            if(S[i][j] > S[i][k]){
                cont++;
            }
        }
    }
    return cont;
}

void ordIns(){
    for(int i = 2; i <= m; i++){
        int j = i;
        int t = P[i];
        while(C[P[j - 1]] > C[t] && j > 1){
            P[j] = P[j - 1];
            j--;
        }
        P[j] = t;
    }
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &M);
    while(M--){
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            scanf("%s" , S[i]);
        }
        for(int i = 1; i <= m; i++){
            P[i] = i;
            C[i] = contInv(i);
        }
        ordIns();
        for(int i = 1; i <= m; i++){
            printf("%s\n", S[P[i]]);
        }
        if(M >= 1)
            printf("\n");
    }

    return 0;
}