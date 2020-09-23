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

    int n, p;

    while (cin >> n >> p) {
        if (n == 0 || p == 0) {
            break;
        }

        vector<vector<int>> pile(p);
        int pos = -1;
        
        for (int i = 0; i < p; i++) {
            int q;

            cin >> q;

            while (q--) {
                int x;

                cin >> x;

                pile[i].push_back(x);

                if (x == 1) {
                    pos = i;
                }
            }
        }

        if (pile[pos].back() == 1) {
            if ((pile[pos].size() > pile[pos - 1].size() && pos - 1 >= 0) || (pile[pos].size() > pile[pos + 1].size() && pos + 1 < p)) {
                cout << 0 << endl;
                continue;
            }
        }

        int ans = 0;

        while (pile[pos].back() != 1) {
            ans++;
            pile[pos].pop_back();
        }

        int l = 0, r = 0;

        for (int i = pos - 1; i >= 0; i--) {
            if (pile[i].size() < pile[pos].size()) {
                break;
            }

            l += pile[i].size() - pile[pos].size() + 1;
        }

        for (int i = pos + 1; i < p; i++) {
            if (pile[i].size() < pile[pos].size()) {
                break;
            }
            
            r += pile[i].size() - pile[pos].size() + 1;
        }

        cout << ans + min(l, r) << endl;
    }

    return 0;
}