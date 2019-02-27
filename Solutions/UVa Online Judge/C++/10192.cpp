#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int T[1000], S[1000], O[1000], n, m, kscm, TM[1001][1001];
char A[1001], B[1001], C[1001];

void SMC(){
	n = strlen(A);
	m = strlen(B);
    for( int i=1; i<=n; i++ ) TM[i][0]=0;
    for( int j=1; j<=m; j++ ) TM[0][j]=0;    
	for( int i=1; i<=n; i++ ) {
		for( int j=1; j<=m; j++ ) {
			if( A[i-1] == B[j-1] )
				TM[i][j] = TM[i-1][j-1]+1;
			else
				TM[i][j] = max(TM[i-1][j], TM[i][j-1]);
		}
	}
}

void GeraSMC(int i, int j, int k){
	if( k > 0 ) {
		if( A[i-1] == B[j-1] ) {
			 k--; i--; j--;
			 C[k] = A[i];
        }
		else if( TM[i-1][j] == k )
			i--;
		else
			j--;
		GeraSMC(i, j, k);
    }
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int cont = 1;
    while(gets(A)){
        if(strcmp(A, "#") == 0) break;
        gets(B);
        SMC();
        cout << "Case #" << cont << ": you can visit at most " << TM[n][m] << " cities." << endl;
        GeraSMC( n, m, TM[n][m] );
        C[TM[n][m]] = '\0'; 
        cont++;
    }

    return 0;
}