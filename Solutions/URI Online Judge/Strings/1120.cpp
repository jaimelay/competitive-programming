#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char d[1];
    string n;
    while(cin >> d >> n){
        if(d[0] == '0' && n == "0") break;
        n.erase(remove(n.begin(), n.end(), d[0]), n.end());

        while(n[0] == '0'){
            n.erase(0, 1);
            if(n.size() == 1) break;
        }

        if(n.empty()) cout << 0 << endl;
        else cout << n << endl;
    }
    return 0;
}