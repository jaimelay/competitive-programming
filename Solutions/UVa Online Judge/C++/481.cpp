#include <iostream>

using namespace std;

int T[10000000], O[10000000], S[10000000], n, kscm;

int SCM() {
    int j, k = 1;
	T[1] = S[1];   O[1] = 1; 	
	for( int i = 2; i <= n; i++ ) {
        if( S[i] > T[k] ) {
            T[++k] = S[i];    O[i] = k;
        } else {
			j = lower_bound( T + 1, T + k, S[i] ) - T;           
            if( S[i] > T[j] )  j++;           
            T[j] = S[i];  O[i] = j;
        }
    }
    return k;
}

void ImprimeSCM( int i, int j, int m ) {
     if( j > 0 ) {
         if( ( O[i] == j ) && ( S[i] < m ) ) {
             ImprimeSCM( i-1, j-1, S[i] );
             cout << S[i] << endl;
         }
         else ImprimeSCM( i-1, j, m );
     }
}

int main(void){
    int i = 1;
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 

    while(cin >> S[i]){
        n++;
        i++;
    }
    
    kscm = SCM();
    cout << kscm << endl;
    cout << "-" << endl;
    ImprimeSCM( n, kscm, 2000000000 );

    return 0;
}