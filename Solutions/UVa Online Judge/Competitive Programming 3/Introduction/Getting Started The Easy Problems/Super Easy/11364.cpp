#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t, n, maior, menor;
    vector<int> v;
    cin >> t;
    while(t--){
        cin >> n;
        v.resize(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        maior = *max_element(v.begin(), v.end());
        menor = *min_element(v.begin(), v.end());
        cout << 2 * (maior - menor) << endl;
    }
    return 0;
}