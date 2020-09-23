#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, j;

    while (cin >> n >> j) {
        if (n == 0 && j == 0) {
            break;
        }

        vector<int> v(n);
        for (auto &x : v) cin >> x;

        vector<int> descartes(13 + 1, 0);
        vector<pair<int, int>> jogador(j + 1, { 0, 0 });

        int pl = 1;

        for (int i = 0; i < n; i++) {
            bool flag = false;

            if (descartes[v[i]]) {
                jogador[pl] = { jogador[pl].first + descartes[v[i]], v[i] };
                descartes[v[i]] = 0;
                flag = true;
            } 

            int z = 0, pl_find = -1;
            
            for (int k = 1; k <= j; k++) {
                if (k != pl) {
                    if (v[i] == jogador[k].second) {
                        if (jogador[k].first > z) {
                            z = jogador[k].first;
                            pl_find = k;
                        }
                    }
                }
            }

            if (pl_find != -1) {
                jogador[pl].first += jogador[pl_find].first;
                jogador[pl].second = v[i];
                jogador[pl_find] = { 0, 0 }; 
                flag = true;
            }
            
            if (v[i] == jogador[pl].second) {
                jogador[pl].first++;
                descartes[v[i]] = 0;
                flag = true;
            }

            if (!flag) {
                descartes[v[i]]++;
                if (pl == j) {
                    pl = 1;
                } else {
                    pl++;
                }
            }
        }
        
        int mx = 0;

        for (int i = 1; i <= j; i++) {
            if (jogador[i].first > mx) {
                mx = jogador[i].first;
            }
        }

        vector<int> ans;

        for (int i = 1; i <= j; i++) {
            if (jogador[i].first == mx) {
                ans.push_back(i);
            }
        }

        cout << mx << " ";
        for (int i = 0; i < int(ans.size()); i++) {
            cout << ans[i] << " \n"[i == int(ans.size()) - 1];
        }
    }

    return 0;
}