#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 100010;

int isAlive[MAXN];
vector<int> killThem, g[MAXN], preOrder;

void DFS(int v) {
    preOrder.push_back(v);
    for (int child = 0; child < (int)g[v].size(); child++) {
        DFS(g[v][child]);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, t, x, id = 1;
    cin >> q;

    isAlive[id] = 1;

    while (q--) {
        cin >> t >> x;

        if (t == 1) {        
            g[x].push_back(++id);
            isAlive[id] = 1;
        } else {
            killThem.push_back(x);
        }
    }

    DFS(1);

    int ptr = 0;
    for (int i = 0; i < (int)killThem.size(); i++) {
        isAlive[killThem[i]] = 0;

        while (!isAlive[preOrder[ptr]] && ptr < (int)preOrder.size()) {
            ptr++;
        }

        cout << preOrder[ptr] << endl;
    }

    return 0;
}