#include <bits/stdc++.h>

using namespace std;

int main(void){
    long long n;

    cin >> n;
    cout << (1LL << __builtin_popcountll(n)) << endl;

    return 0;
}