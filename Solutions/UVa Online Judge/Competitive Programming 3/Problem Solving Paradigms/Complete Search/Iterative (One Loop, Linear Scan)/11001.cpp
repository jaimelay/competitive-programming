#include <bits/stdc++.h>

using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    double v, v0, d, l;
    while(cin >> v >> v0){
        if(v == 0 && v0 == 0) break;

        double maior_l = 0, aux = 0;
        int ans = 0, flag = 0;
        for(int i = 1; ; i++){
            aux = v/i;
            if(aux <= v0) break;
            d = 0.3 * sqrt(aux - v0);
            l = d * i;
            if(l >= maior_l){
                if(fabs(l - maior_l) < 1e-9){
                    ans = 0;
                    break;
                }
                maior_l = l;
                ans = i;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}