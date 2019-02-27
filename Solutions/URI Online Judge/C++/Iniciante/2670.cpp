#include <bits/stdc++.h>

using namespace std;

int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> minutos;
    minutos.push_back((a * 4) + (b * 2));
    minutos.push_back((a * 2) + (c * 2));
    minutos.push_back((b * 2) + (c * 4));
    sort(minutos.begin(), minutos.end());
    cout << minutos[0] << endl;
    return 0;
}