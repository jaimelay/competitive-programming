#include <bits/stdc++.h>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, p;
    while(cin >> n && n){
        cin >> p;
        int tempo[n + 1], pizzas[n + 1], pd[n + 1][p + 1];
        memset(tempo, 0, sizeof(tempo));
        memset(pizzas, 0, sizeof(pizzas));
        memset(pd, 0, sizeof(pd));
        
        for(int i = 1; i <= n; i++)
            cin >> tempo[i] >> pizzas[i];

        for(int i = 0; i < n; i++)
            pd[i][0] = 0;
        for(int i = 0; i < p; i++)
            pd[0][i] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= p; j++){
                if(pizzas[i] > j){
                    pd[i][j] = pd[i - 1][j];
                }else{
                    pd[i][j] = max(pd[i - 1][j - pizzas[i]] + tempo[i], pd[i - 1][j]);
                }
            }
        }

        cout << pd[n][p] << " min." << endl;
    }
    return 0;
}