#include <iostream>

using namespace std;

int S[10001], n;

void SCSM(){
    int sm, cm, fm, ss, cs, fs;
	sm = cm = fm = ss = cs = fs = 0;
	
	for( int i = 1; i <= n; i++ ) {
		if( ( ss + S[i] ) >= 0 ) {
			ss=ss + S[i];
			fs=i;
			if( cs == 0 ) cs=i;
			if( ss > sm ) {
                sm=ss;   cm=cs;   fm=fs;
            }
        }
		else {
			ss = cs = fs = 0;
        }
	}
    if(sm > 0) cout << "The maximum winning streak is " << sm << "." << endl;
    else cout << "Losing streak." << endl;
}

int main(){
    while(cin >> n){
        if(n == 0) break;
        for( int i = 1; i <= n; i++ )
            cin >> S[i];

        SCSM();

    }
    return 0;
}