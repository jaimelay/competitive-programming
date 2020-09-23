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

    int n;

    while (cin >> n) {
        if (n == 0) {
            break;
        }

        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            int c, v;

            cin >> c >> v;
            a.push_back({ c, v });
        }

        int ans = 0;

        while (true) {
            bool flag = false;

            for (int i = 0; i < n; i++) {
                if (a[i].second >= 4) {
                    ans++;
                    a[i].second -= 4;
                    flag = true;
                    continue;
                }
                for (int j = i + 1; j < n; j++) {
                    if (a[j].second >= 2 && a[i].second >= 2) {
                        a[i].second -= 2;
                        a[j].second -= 2;
                        ans++;
                        flag = true;
                    }
                }
            }

            if (!flag) {
                break;
            }
        }

        cout << ans << endl;
    }
    cout << endl;

    return 0;
}