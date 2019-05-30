#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t1, t2, j, t;
    bool V[10001];

    memset(V, false, sizeof(V));
    for(int i = 0; i <= 70; i++){
        t1 = i*i;
        j = i;
        t2 = j*j;
        t = t1 + t2;
        while(t <= 10000){
            V[t] = true;
            j++;
            t2 = j*j;
            t = t1 + t2;
        }
    } 

    while(cin >> n){
        if(n < 0){
            cout << "NO" << endl;
            continue;
        } 
        
        if(V[n] == true) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}