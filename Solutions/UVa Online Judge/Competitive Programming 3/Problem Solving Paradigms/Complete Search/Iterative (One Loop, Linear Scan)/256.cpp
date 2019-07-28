#include <bits/stdc++.h>

using namespace std;

int main(void){
    vector<int> v;
    for(int i = 0; i <= 9999; i++)
        v.push_back(i * i);

    int n;
    while(cin >> n){
        for(int i = 0; i < v.size(); i++){
            if(v[i] >= (int) pow(10, n)) break;
            int l = v[i] / (int) pow(10, n/2);
            int r = v[i] % (int) pow(10, n/2);
            if((l + r) * (l + r) == v[i])
                cout << fixed << setw(n) << setfill('0') << v[i] << endl;
        }
    }
    return 0;
}