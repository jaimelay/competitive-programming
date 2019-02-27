#include <iostream>

using namespace std;

int v[100001], n, montante, maxs;

void Montante(){
    montante = v[1] - v[2];
    maxs = max(v[1], v[2]);
    for(int i = 3; i <= n; i++){
        if( (maxs - v[i]) > montante){
            montante = maxs - v[i];
        }
        if(v[i] > maxs) maxs = v[i];
    }
}

int main(void){
    int t, x;
    cin >> t;
    for(int j = 0; j < t; j++){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> x;
            v[i] = x;
        }
        Montante();
        cout << montante << endl;
    }
    
    return 0;
}