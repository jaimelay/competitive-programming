#include <iostream>
#include <climits>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    int n, t, aux, menor = INT_MAX;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(t < menor){
            menor = t;
            aux = i;
        }
    }
    cout << aux + 1<< endl;
    return 0;
}