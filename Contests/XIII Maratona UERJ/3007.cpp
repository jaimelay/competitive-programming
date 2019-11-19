#include <bits/stdc++.h>

#define MAXN 1001000

using namespace std;

bool vis[MAXN + 10];

int main(void){
    int q, n;
    
    cin >> q;
    while(q--){
        memset(vis, 0, sizeof(vis));

        cin >> n;

        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        for(int i = 0, num; i < n; i++){
            num = v[i];
            while(num <= MAXN){
                vis[num] = true;
                num += num;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 1; j <= MAXN; j++){
                if(vis[j]){
                    if(v[i] + j > MAXN) break;
                    else vis[v[i] + j] = true;
                }
            }
        }

        int ans = -1;
        bool flag = true;
        for(int i = 1; i <= MAXN; i++){
            if(!vis[i] && i > 1000000){
                flag = false;
                break;
            }else if(!vis[i]){
                ans = max(ans, i);
            }
        }
        if(flag) cout << ans << endl;
        else cout << -1 << endl;
    }

    return 0;
}