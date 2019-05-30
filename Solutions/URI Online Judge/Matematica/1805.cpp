#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;
    cout << (a + b) * (abs(a - b) + 1)/2 << endl;
    return 0;
}