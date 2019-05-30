#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n, x, y;
    vector<pair<int, int>> v;
    scanf("%d", &c);
    while(c--){
        scanf("%d", &n);
        for(int i = 0; i < n + 1; i++){
            scanf("%d %d", &x, &y);
            v.push_back(make_pair(x, y));
        }
        double max = 999999999999999999;
        int index = -1;
        for(int i = 1; i <= n; i++){
            ll xi = abs(v[0].first - v[i].first) * abs(v[0].first - v[i].first);
            ll yi = abs(v[0].second - v[i].second) * abs(v[0].second - v[i].second);
            double dist = sqrt(xi + yi);
            if(dist < max){
                max = dist;
                index = i;
            }
        }
        printf("%d\n", index);
        v.clear();
    }
    return 0;
}