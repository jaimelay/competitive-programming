#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int pai[100001], pontos[100001];

int find(int v){
    if(v == pai[v])
        return v;
    return pai[v] = find(pai[v]);
}

bool merge(int v1, int v2){
    v1 = find(v1);
    v2 = find(v2);
    if(v1 == v2) return false;
    pai[v1] = v2;
    pontos[v2] += pontos[v1];
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q, a, b;
    while(cin >> n >> m && n && m){
        for(int i = 1; i <= n; i++){
            pai[i] = i;
            cin >> pontos[i];
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            cin >> q >> a >> b;
            if(q == 1){
                merge(a, b);
            }else{
                int guildRafa = find(1);
                int guildA = find(a);
                int guildB = find(b);
                if(guildRafa == guildA && pontos[guildRafa] > pontos[guildB])
                        ans++;
                if(guildRafa == guildB && pontos[guildRafa] > pontos[guildA])
                        ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}