#include <bits/stdc++.h>

#define endl '\n';

typedef long long ll;

using namespace std;

int n, m, l, x, k, y, tmp;
vector<int> inter[1001];
bitset<1001> b;
queue<int> q;

int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> l;

    for(int i = 1; i <= l; i++){
        cin >> x;
        b.set(x);
    }

    for(int i = 1; i <= n; i++){
        cin >> k;
        q.push(i);
        for(int j = 1; j <= k; j++){
            cin >> tmp;
            inter[i].push_back(tmp);
        }
    }

    int ans = 0;
    for(int i = 1; i <= 2*n; i++){
        k = q.front();
        q.pop();
        for(auto j : inter[k]){
            b.flip(j);
        }
        q.push(k);
        ans++;
        if(b.none()) break;
    }

    if(!b.none()){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    
    return 0;
}