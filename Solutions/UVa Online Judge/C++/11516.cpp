#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

ll houses[100100], m;
int ct, n;

bool isPossible(int mid){
    int usados = 1;
    int alcance = houses[0] + mid;
    for(int i = 0; i < m; i++){
        if(houses[i] > alcance){
            usados++;
            alcance = houses[i] + mid;
            if(usados > n) return false;
        }
    }
    return true;
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> ct;
    while(ct--){
        cin >> n >> m;
        for(int i = 0; i < m; i++)
            cin >> houses[i];
        
        if(n >= m){
            cout << fixed << setprecision(1) << 0.0 << endl;
            continue;
        }

        sort(houses, houses + m);

        double l = 0, r = houses[m - 1], mid = 0;
        while(abs(r - l) > 1e-9){
            mid = (l + r)/2;
            if(isPossible(mid)) r = mid;
            else l = mid;
        }
        
        cout << fixed << setprecision(1) << r/2.0 << endl;
    }
    return 0;
}