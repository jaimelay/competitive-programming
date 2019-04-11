#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, x;

    vector<ll> v;

    while(cin >> n){
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n - 1; i++){
            cout << v[i] << " ";
        }
        cout << v[n - 1] << endl;
        v.clear();
    }
    
    return 0;
}