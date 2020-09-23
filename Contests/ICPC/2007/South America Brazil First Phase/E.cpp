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

        vector<int> v(n);
        map<int, int> mp;

        for (auto &x : v) {
            cin >> x;
            mp[x] = x;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += mp[v[i]];

            for (auto x : mp) {
                mp[x.first]++;
            }

            mp[v[i]] = 1;
        }

        cout << ans << endl;
    }

    return 0;
}