#include <bits/stdc++.h>

using namespace std;

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    char l;
    int e[100], d[100];
    while(cin >> n){
        memset(e, 0, sizeof(e));
        memset(d, 0, sizeof(e));
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> m >> l;
            if(l == 'D'){
                d[m] += 1;
            }else if(l == 'E'){
                e[m] += 1;
            }

            if(d[m] && e[m]){
                ans++;
                d[m]--;
                e[m]--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}